#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn = 105;

int n, a[maxn];
char s[maxn];
LL dp[maxn][maxn][maxn];

LL solve(int L, int R, int x){
    LL& ret = dp[L][R][x];
    if(ret >= 0) return dp[L][R][x];
    if(L > R) return ret = a[x];
    if(L == R) return ret = a[x+1];
    ret = a[x+1] + solve(L+1,R,0);
    for(int i = L+1;i<=R;i++)
        if(s[i]==s[L]) ret = max(ret, solve(L+1,i-1,0)+solve(i,R,x+1));
    return ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    sc(n); scanf("%s", s);
    for(int i=1;i<=n;i++) sc(a[i]);
    printf("%lld\n", solve(0, n-1, 0));
    return 0;
}
