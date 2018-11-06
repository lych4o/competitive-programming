#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld", &x)
#define pb push_back
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 1e5+10;

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k){
        if(k&1) ret=ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
LL f[maxn], g[maxn], n;
int main(){
    g[0]=1; f[1]=1; f[0]=1; g[1]=2;
    for(int i = 2; i < maxn; i++){
        f[i]=(f[i-1]*g[i-2]+f[i-1]*(f[i-1]+1)/2)%mod;
        g[i]=(g[i-1]+f[i])%mod;
    }
    while(cin >> n && n){
        //printf("f[%lld]:%lld, g[%lld]:%lld\n",n/2,f[n/2],n/2-1,g[n/2-1]);
        if(n==1) cout << 1 << endl;
        else if(n&1){
            LL ans = f[n/2]*(f[n/2]+1)/2%mod*g[n/2-1]%mod;
            ans += f[n/2]*(f[n/2]+1)%mod*(f[n/2]+2)%mod*qpow(6,mod-2)%mod;
            ans %= mod;
            cout << ans << endl;
        }else{
            cout << f[n/2]*(f[n/2]+1)/2%mod << endl;
        }
    }
    return 0;
}

