#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const LL mod = 998244353;
LL qpow(LL x, LL k){
    LL res = 1;
    while(k){
        if(k&1) res=res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
const int G = 3;
LL wn[20];
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
const int maxn = 1e5+10;
int n;
LL a[maxn*4], b[maxn*4], fac[maxn];

int main(){
    sc(n);
    for(int i = 0; i < n; i++) sll(a[i]), b[n-i-1]=a[i];
    getwn(); int len = 1; while(len<=2*n) len <<= 1;   
    ntt(a,len); ntt(b,len);
    for(int i = 0; i < len; i++) a[i]=a[i]*b[i]%mod;   
    ntt(a,len,-1);
    LL ans = 0;
    //printf("len:%d\n",len);
    //for(int i=0;i<len;i++) printf("g[%d]:%lld\n",i,a[n+i]);
    for(int i = 1; i <= n-2; i++){
        ans += a[n+i]*2*qpow(i+1,mod-2)%mod*qpow(i+2,mod-2)%mod;
    }
    printf("%lld\n", ans%mod);
    return 0;
}
