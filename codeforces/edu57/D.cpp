#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
int n, a[maxn];
LL dp[maxn][5];
char s[maxn], t[]="hard";
void MIN(LL& x, LL y){x=min(x,y);}
int main(){
	sc(n);
	scanf("%s", s+1);
	for(int i=1;i<=n;i++) sc(a[i]);
	LL INF = 1e9*maxn;
	for(int i=0;i<=n;i++) for(int j=0;j<5;j++) dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++) dp[i][j]=dp[i-1][j];
		for(int j=0;j<4;j++){
			if(s[i]==t[j]){
				MIN(dp[i][j+1],dp[i-1][j]);
				dp[i][j]=dp[i-1][j]+a[i];
			}
		}
		for(int j=0;j<5;j++){
			//printf("dp[%d][%d]:%I64d\n",i,j,dp[i][j]);
		}
	}
	LL ans=INF;
	for(int i=0;i<4;i++){
		MIN(ans, dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}
