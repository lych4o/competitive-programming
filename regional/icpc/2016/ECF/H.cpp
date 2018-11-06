#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 205;

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k>0){
        if(k&1) ret=ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
LL f[maxn][maxn], pw[maxn][maxn*maxn], fac[maxn], g[maxn];
int n, m, k;

int main(){
    int T; sc(T);
    fac[0]=1;
    /*for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<maxn;i++){
        pw[i][0]=1;
        for(int j=1;j<maxn*maxn;j++)
            pw[i][j]=pw[i][j-1]*i%mod;
    }*/
    for(int kase=1;kase<=T;kase++){
        sc(n); sc(m); sc(k);
        LL ans=0;
        for(int i=1;i<=k;i++) ans = (ans+qpow(i-1,n+m-2))%mod;
        ans = ans*n*m%mod*qpow(k,(n-1)*(m-1))%mod;
        printf("Case #%d: %lld\n", kase, (ans+qpow(k,n*m))%mod);
    }
    return 0;
}
