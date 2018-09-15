#include<iostream>
#include<cstring>
#include<cstring>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3+10;

LL a[maxn], k, dp[2][maxn][10];
char s[10];
int n, m;

LL MIN(LL& a, LL b){
    return a = a>b?b:a;
}
LL MAX(LL& a, LL b){
    return a = a>b?a:b;
}
int main(){
    int T; sc(T);
    while(T--){
        sc(n); sc(m); scanf("%lld",&k);
        for(int i = 0; i < n; i++) scanf("%lld",a+i);
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++){
            dp[0][i][j] = INF; dp[1][i][j] = -INF;
        }
        dp[0][0][0] = dp[1][0][0] = k;
        scanf("%s", s);
        for(int i = 0; i < n; i++) for(int j = 0; j <= m; j++){
            if(dp[0][i][j] >= INF) continue;
            //printf("dp[%d][%d]:(%lld,%lld)\n",
              //      i,j,dp[0][i][j],dp[1][i][j]);
            MIN(dp[0][i+1][j],dp[0][i][j]);
            MAX(dp[1][i+1][j],dp[1][i][j]);
            if(j == m) continue;
            LL p, q;
            if(s[j] == '*'){
                p = dp[0][i][j]*a[i], q = dp[1][i][j]*a[i];
            }else if(s[j] == '/'){
                p = dp[0][i][j]/a[i], q = dp[1][i][j]/a[i];
            }else if(s[j] == '+'){
                p = dp[0][i][j]+a[i], q = dp[1][i][j]+a[i];
            }else{
                p = dp[0][i][j]-a[i], q = dp[1][i][j]-a[i];
            }
            if(p > q) swap(p,q);
            MIN(dp[0][i+1][j+1],p); MAX(dp[1][i+1][j+1],q);
        }
        cout << dp[1][n][m] << endl;
    }
    return 0;
}
