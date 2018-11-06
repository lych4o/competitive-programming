#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define debug puts("???")
#define sll(x) scanf("%lld", &x)
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 1e6+10;
LL dp[maxn], add[maxn], sum[maxn];
int n, k;
int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); sc(k);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+i;
        LL ans=2;
        for(int i=k;i>=1;i--){
            if(sum[k]-sum[i-1]>sum[i-1]){
                for(int j=1;j<i;j++) ans=(ans<<1)%mod;
                break;
            }
        }
        memset(add,0,sizeof(add));
        memset(dp,0,sizeof(dp));
        add[k]=1; add[k+1]=-1;
        LL now=0;
        for(int i=k,j=k;i<=n;i++){
            now+=add[i]; now %= mod; dp[i]=now;
            while(j <= n && sum[j]-sum[i] <= sum[i]) j++;

            add[i+1] += dp[i]; add[i+1] %= mod;
            add[j] -= dp[i]; add[j] %= mod;
            //printf("dp[%d]:%lld, [%d,%d)\n",i,dp[i],i+1,j);
        }
        printf("Case #%d: %lld\n", kase, (ans*dp[n]%mod+mod)%mod);
    }
    return 0;
}
