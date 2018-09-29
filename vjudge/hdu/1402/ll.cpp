#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 119 << 23 | 1;
const int G = 3;
LL wn[20];
LL qpow(LL x, int k){
    LL ret = 1;
    while(k > 0){
        if(k&1) ret = ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
void getwn(){ //  千万不要忘记
    for (int i = 0; i < 20; i++) wn[i] = qpow(G, (mod - 1) / (1 << i));
}

void ntt(LL y[], int len, int on=1){
    for (int i = 1, j = (len>>1); i < len - 1; i++){
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
    for (int h = 2, id = 1; h <= len; h <<= 1, id++){
        for (int j = 0; j < len; j += h){ 
            LL w = 1;
            for (int k = j; k < j + h / 2; k++){//记得对原数组取模
                LL u = y[k], t = w * y[k + h / 2] % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) + 2*mod) % mod;
                w = w * wn[id] % mod;
            }
        }
    }
    if (on == -1){
        //  原本的除法要用逆元
        LL inv = qpow(len, mod - 2);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = y[i] * inv % mod;
    }
}

const int maxn = 5e4+10;
char s[maxn];
LL a[maxn*4], b[maxn*4], n1, n2;

int main(){
    while(scanf("%s",s)!=EOF){
        n1 = strlen(s); 
        for(int i=0; i < n1; i++) a[n1-i-1]=s[i]-'0';
        scanf("%s", s); n2 = strlen(s);
        for(int i = 0; i < n2; i++) b[n2-i-1]=s[i]-'0';
        int len = 1; while(len < n1+n2) len <<= 1; 
        for(int i = n1; i < len; i++) a[i]=0;
        for(int i = n2; i < len; i++) b[i]=0;
        getwn(); ntt(a,len); ntt(b,len);
        for(int i = 0; i < len; i++) a[i]=a[i]*b[i]%mod;
        ntt(a,len,-1); 
        int ed = 0;
        for(int i = 0; i < len-1; i++){
            a[i+1] += a[i]/10;
            a[i] %= 10;
            if(a[i]>0) ed = i;
        }
        for(int i = ed; i >= 0; i--){
            printf("%lld", a[i]);
        }puts("");
    }
    return 0;
}
