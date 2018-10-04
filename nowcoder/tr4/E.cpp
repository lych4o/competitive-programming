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
int n;
LL w[maxn], fac[maxn];

int main(){
    sc(n);
    for(int i = 1; i <= n; i++) sll(w[i]);
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    LL ans = 0, k = n*(n-1)*(n-2)/3%mod*fac[n-3]%mod;
    for(int i = 2; i <= n-1; i++){
        ans += k*w[i-1]%mod*w[i+1]%mod;
    }
    ans %= mod;
    printf("%lld\n", ans*qpow(fac[n],mod-2)%mod);
    return 0;
}
