#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 64;

int len;
LL dp[maxn][2][2][2], n, bit[maxn], sum[maxn];

void get(){
    LL tmp = n; len = 0;
    while(tmp > 0){
        bit[len] = tmp&1;
        sum[len] = bit[len]<<len;
        if(len>0) sum[len] = (sum[len]+sum[len-1])%mod;
        len++; tmp >>= 1;
    }
}
inline LL calc(int p, int lb, int rb){
    if(p < 0) return 0;
    if(p == 0) return 1;
    LL ret = lb ? (sum[p-1]+1) : (1LL<<(p))%mod;
    ret *= rb ? (sum[p-1]+1) : (1LL<<(p))%mod;
    return ret%mod;
}
///pos, lbound, rbound, match
LL dfs(int p, int lb, int rb, int mc){
    if(p < 0) return 0;
    LL& now = dp[p][lb][rb][mc];
    if(now >= 0) return now;
    now = 0;
    int ul = lb?bit[p]:1, ur = rb?bit[p]:1;
    for(int i = 0; i <= ul; i++) for(int j = 0; j <= ur; j++){
        int nlb = lb && (i==ul), nrb = rb && (j==ur), nmc = mc && (i==j);
        now += (!nmc)*calc(p,nlb,nrb)*(i+j);
        now += dfs(p-1,nlb,nrb,nmc);
    } now %= mod;
    //printf("dp[%d][%d][%d][%d]:%lld\n",p,lb,rb,mc,now);
    return now;
}

int main(){
    int T; sc(T); LL iv2 = (mod+1)/2;
    for(int kase = 1; kase <= T; kase++){
        sll(n); get();
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %lld\n", kase, iv2*dfs(len-1,1,1,1)%mod);
    }
    return 0;
}
