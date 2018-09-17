#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define sc(x) scanf("%d", &x)
#define pb push_back

using namespace std;
typedef long long LL;
const int maxn = 1e5+10;

char s[maxn];
int dp[maxn][2], n, sum[maxn][2];
int main(){
    int T; sc(T);
    while(T--){
        scanf("%s", s);
        n = strlen(s);
        dp[0][s[0]-'0'] = 1; dp[0][!(s[0]-'0')] = 0;
        LL ans = 0, pre = 0;
        for(int i = 1; i <= n; i++){
            //printf("dp[%d]:(%d:%d, %d:%d)\n",i-1,0,dp[i-1][0],1,dp[i-1][1]);
            pre += dp[i-1][0]*2 + dp[i-1][1];
            ans += pre;
            if(s[i] != s[i-1]){
                dp[i][1] = dp[i-1][1]+dp[i-1][0];
                dp[i][0] = 0;
            }else{
                dp[i][0] = dp[i-1][0]+dp[i-1][1];
                dp[i][1] = 0;
            }
            if(i < n) dp[i][s[i]-'0']++;
        }
        cout << ans << endl;
    }
    return 0;
}
