#include<bits/stdc++.h>
#define sll(x) scanf("%lld", &x)
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const int maxn = 4e3+10;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
int n;
LL a[maxn], b[maxn], dp[maxn][2], s[maxn][2], ds[maxn][2];

//[l, r)
inline LL query(int t, int l, int r, int p){
    LL num = s[r-1][t]-s[l-1][t], ret = ds[r-1][t]-ds[l-1][t];
    if(p < l) ret -= num*p;
    else ret = num*p -ret;
    return ret;
}
int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); 
        for(int i = 1; i <= n; i++){
            sll(a[i]), sll(b[i]);
            s[i][0] = s[i-1][0]+a[i];
            s[i][1] = s[i-1][1]+b[i];
            ds[i][0] = ds[i-1][0] + a[i]*i;
            ds[i][1] = ds[i-1][1] + b[i]*i;
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = dp[0][1] = 0;
        for(int i=1;i<=n;i++) for(int j=0;j<i;j++) for(int t=0;t<2;t++){
            int m = (i+1+j)>>1;
            LL add = 0;
            if(i==n && j==0) continue;
            else if(i==n) add = query(!t,j+1,i+1,j);
            else if(j==0) add = query(!t,j+1,i+1,i+1);
            else add = query(!t,j+1,m+1,j)+query(!t,m+1,i+1,i+1);
            dp[i][t] = min(dp[i][t], dp[j][!t]+add);
        }
        printf("Case #%d: %lld\n", kase, min(dp[n][1],dp[n][0]));
   }
    return 0;
}
