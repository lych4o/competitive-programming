#include <arm_neon.h>
#include <stdint.h>
#include <stddef.h>
#include <cstring>

template<>
inline void CodeHelper<6>::compact_code8(uint8_t * __restrict__ compact, const uint8_t * __restrict__ raw, size_t D) {
    // 清零
    memset(compact, 0, D * 3 / 8);

    // 低2位
    for (size_t i = 0; i < D; i += 4) {
        uint8_t byte = 0;
        byte |= (raw[i + 0] & 0x3) << 0;
        byte |= (raw[i + 1] & 0x3) << 2;
        byte |= (raw[i + 2] & 0x3) << 4;
        byte |= (raw[i + 3] & 0x3) << 6;
        compact[i / 4] = byte;
    }
    // 第3位
    for (size_t i = 0; i < D; i += 8) {
        uint8_t byte = 0;
        for (int k = 0; k < 8; ++k) {
            byte |= ((raw[i + k] >> 2) & 0x1) << k;
        }
        compact[D / 4 + i / 8] = byte;
    }
}

template<>
inline void CodeHelper<6>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // NEON优化低2位解包
    for (size_t i = 0; i < D; i += 16) {
        uint8x16_t bytes = vld1q_u8(compact + i / 4);
        uint8_t tmp[16] __attribute__((aligned(16)));
        for (int j = 0; j < 16; ++j) {
            uint8_t byte = bytes[j];
            tmp[j * 4 + 0] = (byte >> 0) & 0x3;
            tmp[j * 4 + 1] = (byte >> 2) & 0x3;
            tmp[j * 4 + 2] = (byte >> 4) & 0x3;
            tmp[j * 4 + 3] = (byte >> 6) & 0x3;
        }
        vst1q_u8(raw + i, vld1q_u8(tmp));
        vst1q_u8(raw + i + 8, vld1q_u8(tmp + 8));
    }
    // 第3位合成
    for (size_t i = 0; i < D; ++i) {
        uint8_t bit3 = (compact[D / 4 + i / 8] >> (i % 8)) & 0x1;
        raw[i] |= bit3 << 2;
    }
}

template<>
inline uint32_t CodeHelper<6>::compute_uint_ip(const uint8_t * __restrict__ query, const uint8_t * __restrict__ compact, size_t D) {
    uint32_t sum = 0;
    uint8_t val[64] __attribute__((aligned(16)));
    for (size_t i = 0; i < D; i += 64) {
        // NEON优化低2位解包
        for (int j = 0; j < 16; ++j) {
            uint8_t byte = compact[(i + j * 4) / 4];
            val[j * 4 + 0] = (byte >> 0) & 0x3;
            val[j * 4 + 1] = (byte >> 2) & 0x3;
            val[j * 4 + 2] = (byte >> 4) & 0x3;
            val[j * 4 + 3] = (byte >> 6) & 0x3;
        }
        // 第3位合成
        for (int j = 0; j < 64; ++j) {
            uint8_t bit3 = (compact[D / 4 + (i + j) / 8] >> ((i + j) % 8)) & 0x1;
            val[j] |= bit3 << 2;
        }
        // NEON并行内积
        uint8x16_t q0 = vld1q_u8(query + i);
        uint8x16_t q1 = vld1q_u8(query + i + 16);
        uint8x16_t q2 = vld1q_u8(query + i + 32);
        uint8x16_t q3 = vld1q_u8(query + i + 48);

        uint8x16_t v0 = vld1q_u8(val);
        uint8x16_t v1 = vld1q_u8(val + 16);
        uint8x16_t v2 = vld1q_u8(val + 32);
        uint8x16_t v3 = vld1q_u8(val + 48);

        uint16x8_t prod0 = vmull_u8(vget_low_u8(q0), vget_low_u8(v0));
        uint16x8_t prod1 = vmull_u8(vget_high_u8(q0), vget_high_u8(v0));
        uint16x8_t prod2 = vmull_u8(vget_low_u8(q1), vget_low_u8(v1));
        uint16x8_t prod3 = vmull_u8(vget_high_u8(q1), vget_high_u8(v1));
        uint16x8_t prod4 = vmull_u8(vget_low_u8(q2), vget_low_u8(v2));
        uint16x8_t prod5 = vmull_u8(vget_high_u8(q2), vget_high_u8(v2));
        uint16x8_t prod6 = vmull_u8(vget_low_u8(q3), vget_low_u8(v3));
        uint16x8_t prod7 = vmull_u8(vget_high_u8(q3), vget_high_u8(v3));

        uint32x4_t acc = vdupq_n_u32(0);
        acc = vpadalq_u16(acc, prod0);
        acc = vpadalq_u16(acc, prod1);
        acc = vpadalq_u16(acc, prod2);
        acc = vpadalq_u16(acc, prod3);
        acc = vpadalq_u16(acc, prod4);
        acc = vpadalq_u16(acc, prod5);
        acc = vpadalq_u16(acc, prod6);
        acc = vpadalq_u16(acc, prod7);

        sum += vaddvq_u32(acc);
    }
    return sum;
}

template<>
inline void CodeHelper<5>::compact_code8(uint8_t * __restrict__ compact, const uint8_t * __restrict__ raw, size_t D) {
    // 清零
    memset(compact, 0, D * 5 / 8);

    // 低4位
    for (size_t i = 0; i < D; ++i) {
        compact[i / 2] |= ((raw[i] & 0xF) << (4 * (i % 2)));
    }
    // 第5位
    for (size_t i = 0; i < D; ++i) {
        uint8_t bit5 = (raw[i] >> 4) & 0x1;
        compact[D / 2 + i / 8] |= bit5 << (i % 8);
    }
}

template<>
inline void CodeHelper<5>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // NEON优化低4位解包
    for (size_t i = 0; i < D; i += 32) {
        uint8x16_t c0 = vld1q_u8(compact + i / 2);
        uint8x16_t c1 = vld1q_u8(compact + i / 2 + 16);
        uint8_t tmp[32] __attribute__((aligned(16)));
        for (int j = 0; j < 16; ++j) {
            tmp[j * 2]     = c0[j] & 0xF;
            tmp[j * 2 + 1] = (c0[j] >> 4) & 0xF;
        }
        for (int j = 0; j < 16; ++j) {
            tmp[16 + j * 2]     = c1[j] & 0xF;
            tmp[16 + j * 2 + 1] = (c1[j] >> 4) & 0xF;
        }
        vst1q_u8(raw + i, vld1q_u8(tmp));
        vst1q_u8(raw + i + 16, vld1q_u8(tmp + 16));
    }
    // 第5位合成
    for (size_t i = 0; i < D; ++i) {
        uint8_t bit5 = (compact[D / 2 + i / 8] >> (i % 8)) & 0x1;
        raw[i] |= bit5 << 4;
    }
}

template<>
inline uint32_t CodeHelper<5>::compute_uint_ip(const uint8_t * __restrict__ query, const uint8_t * __restrict__ compact, size_t D) {
    uint32_t sum = 0;
    uint8_t val[64] __attribute__((aligned(16)));
    for (size_t i = 0; i < D; i += 64) {
        // NEON优化低4位解包
        for (int j = 0; j < 32; ++j) {
            uint8_t byte = compact[(i + j * 2) / 2];
            val[j * 2]     = byte & 0xF;
            val[j * 2 + 1] = (byte >> 4) & 0xF;
        }
        // 第5位合成
        for (int j = 0; j < 64; ++j) {
            uint8_t bit5 = (compact[D / 2 + (i + j) / 8] >> ((i + j) % 8)) & 0x1;
            val[j] |= bit5 << 4;
        }
        // NEON并行内积
        uint8x16_t q0 = vld1q_u8(query + i);
        uint8x16_t q1 = vld1q_u8(query + i + 16);
        uint8x16_t q2 = vld1q_u8(query + i + 32);
        uint8x16_t q3 = vld1q_u8(query + i + 48);

        uint8x16_t v0 = vld1q_u8(val);
        uint8x16_t v1 = vld1q_u8(val + 16);
        uint8x16_t v2 = vld1q_u8(val + 32);
        uint8x16_t v3 = vld1q_u8(val + 48);

        uint16x8_t prod0 = vmull_u8(vget_low_u8(q0), vget_low_u8(v0));
        uint16x8_t prod1 = vmull_u8(vget_high_u8(q0), vget_high_u8(v0));
        uint16x8_t prod2 = vmull_u8(vget_low_u8(q1), vget_low_u8(v1));
        uint16x8_t prod3 = vmull_u8(vget_high_u8(q1), vget_high_u8(v1));
        uint16x8_t prod4 = vmull_u8(vget_low_u8(q2), vget_low_u8(v2));
        uint16x8_t prod5 = vmull_u8(vget_high_u8(q2), vget_high_u8(v2));
        uint16x8_t prod6 = vmull_u8(vget_low_u8(q3), vget_low_u8(v3));
        uint16x8_t prod7 = vmull_u8(vget_high_u8(q3), vget_high_u8(v3));

        uint32x4_t acc = vdupq_n_u32(0);
        acc = vpadalq_u16(acc, prod0);
        acc = vpadalq_u16(acc, prod1);
        acc = vpadalq_u16(acc, prod2);
        acc = vpadalq_u16(acc, prod3);
        acc = vpadalq_u16(acc, prod4);
        acc = vpadalq_u16(acc, prod5);
        acc = vpadalq_u16(acc, prod6);
        acc = vpadalq_u16(acc, prod7);

        sum += vaddvq_u32(acc);
    }
    return sum;
}

template<>
inline void CodeHelper<6>::compact_code8(uint8_t * __restrict__ compact, const uint8_t * __restrict__ raw, size_t D) {
    // 清零
    memset(compact, 0, D * 6 / 8);

    // 低4位
    for (size_t i = 0; i < D; ++i) {
        compact[i / 2] |= ((raw[i] & 0xF) << (4 * (i % 2)));
    }
    // 第5/6位
    for (size_t i = 0; i < D; ++i) {
        uint8_t bits_56 = (raw[i] >> 4) & 0x3;
        compact[D / 2 + i / 4] |= bits_56 << (2 * (i % 4));
    }
}

template<>
inline void CodeHelper<6>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // NEON优化低4位解包
    for (size_t i = 0; i < D; i += 32) {
        uint8x16_t c0 = vld1q_u8(compact + i / 2);
        uint8x16_t c1 = vld1q_u8(compact + i / 2 + 16);
        uint8_t tmp[32] __attribute__((aligned(16)));
        for (int j = 0; j < 16; ++j) {
            tmp[j * 2]     = c0[j] & 0xF;
            tmp[j * 2 + 1] = (c0[j] >> 4) & 0xF;
        }
        for (int j = 0; j < 16; ++j) {
            tmp[16 + j * 2]     = c1[j] & 0xF;
            tmp[16 + j * 2 + 1] = (c1[j] >> 4) & 0xF;
        }
        vst1q_u8(raw + i, vld1q_u8(tmp));
        vst1q_u8(raw + i + 16, vld1q_u8(tmp + 16));
    }
    // 第5/6位合成
    for (size_t i = 0; i < D; ++i) {
        uint8_t bits_56 = (compact[D / 2 + i / 4] >> (2 * (i % 4))) & 0x3;
        raw[i] |= bits_56 << 4;
    }
}

template<>
inline uint32_t CodeHelper<6>::compute_uint_ip(const uint8_t * __restrict__ query, const uint8_t * __restrict__ compact, size_t D) {
    uint32_t sum = 0;
    uint8_t val[64] __attribute__((aligned(16)));
    for (size_t i = 0; i < D; i += 64) {
        // NEON优化低4位解包
        for (int j = 0; j < 32; ++j) {
            uint8_t byte = compact[(i + j * 2) / 2];
            val[j * 2]     = byte & 0xF;
            val[j * 2 + 1] = (byte >> 4) & 0xF;
        }
        // 第5/6位合成
        for (int j = 0; j < 64; ++j) {
            uint8_t bits_56 = (compact[D / 2 + (i + j) / 4] >> (2 * ((i + j) % 4))) & 0x3;
            val[j] |= bits_56 << 4;
        }
        // NEON并行内积
        uint8x16_t q0 = vld1q_u8(query + i);
        uint8x16_t q1 = vld1q_u8(query + i + 16);
        uint8x16_t q2 = vld1q_u8(query + i + 32);
        uint8x16_t q3 = vld1q_u8(query + i + 48);

        uint8x16_t v0 = vld1q_u8(val);
        uint8x16_t v1 = vld1q_u8(val + 16);
        uint8x16_t v2 = vld1q_u8(val + 32);
        uint8x16_t v3 = vld1q_u8(val + 48);

        uint16x8_t prod0 = vmull_u8(vget_low_u8(q0), vget_low_u8(v0));
        uint16x8_t prod1 = vmull_u8(vget_high_u8(q0), vget_high_u8(v0));
        uint16x8_t prod2 = vmull_u8(vget_low_u8(q1), vget_low_u8(v1));
        uint16x8_t prod3 = vmull_u8(vget_high_u8(q1), vget_high_u8(v1));
        uint16x8_t prod4 = vmull_u8(vget_low_u8(q2), vget_low_u8(v2));
        uint16x8_t prod5 = vmull_u8(vget_high_u8(q2), vget_high_u8(v2));
        uint16x8_t prod6 = vmull_u8(vget_low_u8(q3), vget_low_u8(v3));
        uint16x8_t prod7 = vmull_u8(vget_high_u8(q3), vget_high_u8(v3));

        uint32x4_t acc = vdupq_n_u32(0);
        acc = vpadalq_u16(acc, prod0);
        acc = vpadalq_u16(acc, prod1);
        acc = vpadalq_u16(acc, prod2);
        acc = vpadalq_u16(acc, prod3);
        acc = vpadalq_u16(acc, prod4);
        acc = vpadalq_u16(acc, prod5);
        acc = vpadalq_u16(acc, prod6);
        acc = vpadalq_u16(acc, prod7);

        sum += vaddvq_u32(acc);
    }
    return sum;
}

template<>
inline void CodeHelper<7>::compact_code8(uint8_t * __restrict__ compact, const uint8_t * __restrict__ raw, size_t D) {
    // 清零
    memset(compact, 0, D * 7 / 8);

    // 低4位
    for (size_t i = 0; i < D; ++i) {
        compact[i / 2] |= ((raw[i] & 0xF) << (4 * (i % 2)));
    }
    // 第5/6位
    for (size_t i = 0; i < D; ++i) {
        uint8_t bits_56 = (raw[i] >> 4) & 0x3;
        compact[D / 2 + i / 4] |= bits_56 << (2 * (i % 4));
    }
    // 第7位
    for (size_t i = 0; i < D; ++i) {
        uint8_t bit7 = (raw[i] >> 6) & 0x1;
        compact[D * 3 / 4 + i / 8] |= bit7 << (i % 8);
    }
}

template<>
inline void CodeHelper<7>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // NEON优化低4位解包
    for (size_t i = 0; i < D; i += 32) {
        uint8x16_t c0 = vld1q_u8(compact + i / 2);
        uint8x16_t c1 = vld1q_u8(compact + i / 2 + 16);
        uint8_t tmp[32] __attribute__((aligned(16)));
        for (int j = 0; j < 16; ++j) {
            tmp[j * 2]     = c0[j] & 0xF;
            tmp[j * 2 + 1] = (c0[j] >> 4) & 0xF;
        }
        for (int j = 0; j < 16; ++j) {
            tmp[16 + j * 2]     = c1[j] & 0xF;
            tmp[16 + j * 2 + 1] = (c1[j] >> 4) & 0xF;
        }
        vst1q_u8(raw + i, vld1q_u8(tmp));
        vst1q_u8(raw + i + 16, vld1q_u8(tmp + 16));
    }
    // 第5/6位和第7位合成
    for (size_t i = 0; i < D; ++i) {
        uint8_t bits_56 = (compact[D / 2 + i / 4] >> (2 * (i % 4))) & 0x3;
        raw[i] |= bits_56 << 4;
        uint8_t bit7 = (compact[D * 3 / 4 + i / 8] >> (i % 8)) & 0x1;
        raw[i] |= bit7 << 6;
    }
}

template<>
inline uint32_t CodeHelper<7>::compute_uint_ip(const uint8_t * __restrict__ query, const uint8_t * __restrict__ compact, size_t D) {
    uint32_t sum = 0;
    uint8_t val[64] __attribute__((aligned(16)));
    for (size_t i = 0; i < D; i += 64) {
        // NEON优化低4位解包
        for (int j = 0; j < 32; ++j) {
            uint8_t byte = compact[(i + j * 2) / 2];
            val[j * 2]     = byte & 0xF;
            val[j * 2 + 1] = (byte >> 4) & 0xF;
        }
        // 第5/6位和第7位合成
        for (int j = 0; j < 64; ++j) {
            uint8_t bits_56 = (compact[D / 2 + (i + j) / 4] >> (2 * ((i + j) % 4))) & 0x3;
            val[j] |= bits_56 << 4;
            uint8_t bit7 = (compact[D * 3 / 4 + (i + j) / 8] >> ((i + j) % 8)) & 0x1;
            val[j] |= bit7 << 6;
        }
        // NEON并行内积
        uint8x16_t q0 = vld1q_u8(query + i);
        uint8x16_t q1 = vld1q_u8(query + i + 16);
        uint8x16_t q2 = vld1q_u8(query + i + 32);
        uint8x16_t q3 = vld1q_u8(query + i + 48);

        uint8x16_t v0 = vld1q_u8(val);
        uint8x16_t v1 = vld1q_u8(val + 16);
        uint8x16_t v2 = vld1q_u8(val + 32);
        uint8x16_t v3 = vld1q_u8(val + 48);

        uint16x8_t prod0 = vmull_u8(vget_low_u8(q0), vget_low_u8(v0));
        uint16x8_t prod1 = vmull_u8(vget_high_u8(q0), vget_high_u8(v0));
        uint16x8_t prod2 = vmull_u8(vget_low_u8(q1), vget_low_u8(v1));
        uint16x8_t prod3 = vmull_u8(vget_high_u8(q1), vget_high_u8(v1));
        uint16x8_t prod4 = vmull_u8(vget_low_u8(q2), vget_low_u8(v2));
        uint16x8_t prod5 = vmull_u8(vget_high_u8(q2), vget_high_u8(v2));
        uint16x8_t prod6 = vmull_u8(vget_low_u8(q3), vget_low_u8(v3));
        uint16x8_t prod7 = vmull_u8(vget_high_u8(q3), vget_high_u8(v3));

        uint32x4_t acc = vdupq_n_u32(0);
        acc = vpadalq_u16(acc, prod0);
        acc = vpadalq_u16(acc, prod1);
        acc = vpadalq_u16(acc, prod2);
        acc = vpadalq_u16(acc, prod3);
        acc = vpadalq_u16(acc, prod4);
        acc = vpadalq_u16(acc, prod5);
        acc = vpadalq_u16(acc, prod6);
        acc = vpadalq_u16(acc, prod7);

        sum += vaddvq_u32(acc);
    }
    return sum;
}
