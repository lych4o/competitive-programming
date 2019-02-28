#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 998244353;
const int maxn = 1e6+10;

LL qpow(LL x, LL k){
    LL ret=1;
    while(k>0){
        if(k&1) ret=ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
/*******comb*****/
const int maxc = 1e6+10;
int FAC[maxc], IVF[maxc], IV[maxc];
void init(){
    IV[1] = FAC[0] = FAC[1] = IVF[0] = IVF[1] = 1;
    for(int i = 2; i < maxc; i++){
        FAC[i] = 1LL*FAC[i-1]*i%mod;
        IV[i] = 1LL*(mod-mod/i)*IV[mod%i]%mod;
        IVF[i] = 1LL*IVF[i-1]*IV[i]%mod;
    }
}
LL comb(int x, int y){
    if(x < y) swap(x,y);
    return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;
}/*******comb******/

LL n, m, k;
int main(){
    init();
    cin >> n >> m >> k;
    LL ans = qpow(n,k+2);
    ans = ans*qpow(((n*n-m)%mod+mod)%mod,mod-2);
    LL pp = m*qpow(n*n%mod,mod-2)%mod;
    ans = (1-qpow(pp,k/2+1)+mod)%mod*ans%mod;
    cout << ans << endl;
    return 0;
}
