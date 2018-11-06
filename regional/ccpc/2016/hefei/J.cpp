#include<bits/stdc++.h>
#define mk make_pair
#define debug puts("???")
#define F first
#define S second
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%lld",&x)
#define pLL pair<LL, LL>
using namespace std;
typedef long long LL;
const int maxn = 670;
LL n,m,mod,f[maxn][maxn],C[maxn][maxn];
pLL ff(LL x, LL y){
    LL c=0;
    while(y>0){
        c++;
        LL t=x%y;
        x = y;
        y = t;
    }
    return mk(c,c*x*x);
}
int main(){
    for(int i=1;i<maxn;i++)for(int j=0;j<i;j++){
        f[j][i] = ff(j,i).S;
        C[j][i] = ff(j,i).F;
    }
    int T; sc(T);
    while(T--){
        sll(n); sll(m); sll(mod);
        LL ans=0;
        for(LL i=1;i<=m;i++)for(LL j=0;j<i;j++){
            LL tot=(n-j)/i;
            LL c=C[j][i];
            LL d=c*c*i*i/f[j][i];
            LL a0=0;
            LL q=tot/c;
            LL beg=tot/c*c;
            
            LL pa=ans;
            for(LL k=j, t=0; t<c; t++, k+=i)
                a0 = (a0 + k*i/f[j][i])%mod;
            ans = (ans + (a0+(a0+d*(q-1)))*q/2%mod)%mod;
            for(LL k=beg*i+j; k<=n; k+=i)
                ans = (ans + k*i/f[j][i])%mod;
            //printf("i:%lld,j:%lld,c:%lld,a0:%lld,q:%lld,d:%lld,ans:%lld\n",
              //  i,j,c,a0,q,d,ans-pa);

        }
        printf("%lld\n", ans);
    }
    return 0;
}//
