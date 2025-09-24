template<>
inline void CodeHelper<4>::compact_code8(uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // 每两个原始元素压缩为一个字节
    for (size_t i = 0; i < D; i += 2) {
        compact[i / 2] = (raw[i] & 0xF) | ((raw[i + 1] & 0xF) << 4);
    }
}

template<>
inline void CodeHelper<4>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // NEON优化解包
    for (size_t i = 0; i < D; i += 32) {
        uint8x16_t bytes = vld1q_u8(compact + i / 2);
        uint8_t tmp[32] __attribute__((aligned(16)));
        for (int j = 0; j < 16; ++j) {
            tmp[j * 2]     = bytes[j] & 0xF;
            tmp[j * 2 + 1] = (bytes[j] >> 4) & 0xF;
        }
        vst1q_u8(raw + i, vld1q_u8(tmp));
        vst1q_u8(raw + i + 16, vld1q_u8(tmp + 16));
    }
}

template<>
inline uint32_t CodeHelper<4>::compute_uint_ip(const uint8_t * __restrict__ query, const uint8_t * __restrict__ compact, size_t D) {
    uint32_t sum = 0;
    for (size_t i = 0; i < D; i += 64) {
        // 一次加载64字节
        uint8x16x4_t bytes = vld1q_u8_x4(compact + i / 2);

        uint8x16_t low4_0 = vandq_u8(bytes.val[0], vdupq_n_u8(0xF));
        uint8x16_t low4_1 = vandq_u8(bytes.val[1], vdupq_n_u8(0xF));
        uint8x16_t low4_2 = vandq_u8(bytes.val[2], vdupq_n_u8(0xF));
        uint8x16_t low4_3 = vandq_u8(bytes.val[3], vdupq_n_u8(0xF));

        uint8x16_t high4_0 = vshrq_n_u8(bytes.val[0], 4);
        uint8x16_t high4_1 = vshrq_n_u8(bytes.val[1], 4);
        uint8x16_t high4_2 = vshrq_n_u8(bytes.val[2], 4);
        uint8x16_t high4_3 = vshrq_n_u8(bytes.val[3], 4);

        // 拼成64维向量
        uint8_t val[64] __attribute__((aligned(16)));
        vst1q_u8(val,      low4_0);
        vst1q_u8(val + 16, low4_1);
        vst1q_u8(val + 32, low4_2);
        vst1q_u8(val + 48, low4_3);
        vst1q_u8(val +  8, high4_0);
        vst1q_u8(val + 24, high4_1);
        vst1q_u8(val + 40, high4_2);
        vst1q_u8(val + 56, high4_3);

        // NEON加载查询向量
        uint8x16x4_t q = vld1q_u8_x4(query + i);

        // 使用 vdotq 指令
        uint32x4_t acc = vdupq_n_u32(0);
        acc = vdotq_u32(acc, q.val[0], vld1q_u8(val));
        acc = vdotq_u32(acc, q.val[1], vld1q_u8(val + 16));
        acc = vdotq_u32(acc, q.val[2], vld1q_u8(val + 32));
        acc = vdotq_u32(acc, q.val[3], vld1q_u8(val + 48));

        sum += vaddvq_u32(acc);
    }
    return sum;
}

template<>
inline void CodeHelper<2>::compact_code8(uint8_t * __restrict__ compact, const uint8_t * __restrict__ raw, size_t D) {
    // 每4个原始元素压缩为1字节
    for (size_t i = 0; i < D; i += 4) {
        compact[i / 4] = ((raw[i + 0] & 0x3) << 0) |
                         ((raw[i + 1] & 0x3) << 2) |
                         ((raw[i + 2] & 0x3) << 4) |
                         ((raw[i + 3] & 0x3) << 6);
    }
}

template<>
inline void CodeHelper<2>::decompact_code8(const uint8_t * __restrict__ compact, uint8_t * __restrict__ raw, size_t D) {
    // 非SIMD版本，确保正确性
    for (size_t i = 0; i < D; i += 4) {
        uint8_t byte = compact[i / 4];
        raw[i + 0] = (byte >> 0) & 0x3;
        raw[i + 1] = (byte >> 2) & 0x3;
        raw[i + 2] = (byte >> 4) & 0x3;
        raw[i + 3] = (byte >> 6) & 0x3;
    }
}
