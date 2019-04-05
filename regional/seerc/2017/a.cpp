#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 1e5+10, maxk = 1e3+10;
int n, k, d[30];
char s[maxn], t[maxk];
int dp[2][maxn], sum[2][maxn];

int main(){
	sc(k); sc(n);
	for(int i=0;i<26;i++) sc(d[i]);
	scanf("%s%s",t+1,s+1);
	int now=0,pre=1;
	for(int i=1;i<=n;i++){
		dp[pre][i]=(s[i]==t[1]);
		sum[pre][i]=sum[pre][i-1]+dp[pre][i];
	}
	for(int i=2;i<=k;i++){
		memset(sum[now],0,sizeof(int)*(n+5));
		memset(dp[now],0,sizeof(int)*(n+5));
		for(int j=1;j<=n;j++){
			int dd = d[t[i-1]-'A']+1;
			dp[now][j]=(t[i]==s[j])*sum[pre][max(j-dd,0)];
			sum[now][j]=(sum[now][j-1]+dp[now][j])%mod;
		}
		swap(now,pre);
	}
	LL ans = 0;
	for(int i=1;i<=n;i++) ans += dp[pre][i];
	printf("%lld\n", ans%mod);
	return 0;
}
