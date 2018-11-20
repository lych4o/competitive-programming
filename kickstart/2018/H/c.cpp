#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define F first
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
/*************comb*********/
const int maxc = 2e6+10;
int FAC[maxc], IVF[maxc], IV[maxc], pw2[maxc];
void init(){
    IV[1] = FAC[0] = FAC[1] = IVF[0] = IVF[1] = 1;
    pw2[0]=1; pw2[1]=2;
    for(int i = 2; i < maxc; i++){
        pw2[i]=pw2[i-1]*2%mod;
        FAC[i] = 1LL*FAC[i-1]*i%mod;
        IV[i] = 1LL*(mod-mod/i)*IV[mod%i]%mod;
        IVF[i] = 1LL*IVF[i-1]*IV[i]%mod;
    }
}
LL comb(int x, int y){
    if(x < y) return 0;
    return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;
}/***********comb**********/

int n, m;
inline LL f(int x){
    return comb(m,x)*pw2[x]%mod*FAC[2*n-x]%mod;
}
LL solve(){
    LL ret=0;
    for(int i=0;i<=m;i++){
        LL k = (i%2)?-1:1;
        ret += k*f(i);
    }
    return (ret%mod+mod)%mod;
}
int main(){
    init();
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); sc(m);
        printf("Case #%d: %lld\n",kase,solve());
    }
    return 0;
}
