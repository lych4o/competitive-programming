#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("I64d",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const int mod = 998244353;
const int maxn = 1e5+10, maxm=205;
int sum[2][2][maxm], dp[maxn][maxm][2];
inline void _add(int& x, int y){
	x=((x+y)>=mod?(x+y-mod):(x+y));
}
void add(int p1, int p2, int x, int v){
	for(int i=x;i<maxm;i+=i&-i)
		_add(sum[p1][p2][i],v);
}
int que(int p1, int p2, int x){
	int ret=0;
	for(int i=x;i>0;i-=i&-i)
		_add(ret,sum[p1][p2][i]);
	return ret;
}
const int up=200;
int n, a[maxn];
int main(){
	sc(n);
	for(int i=1;i<=n;i++) sc(a[i]);
	int now=0,nxt=1;
	memset(dp,0,sizeof(dp));
	if(a[1]>0) dp[1][a[1]][0]=1, add(now,0,a[1],1);
	else for(int i=1;i<=up;i++) dp[1][i][0]=1, add(now,0,i,1);
	for(int i=2;i<=n;i++){
		memset(sum[nxt],0,sizeof(sum[nxt]));
		int x=1,y=up;
		if(a[i]>0) x=y=a[i];
		for(int j=x;j<=y;j++){
			dp[i][j][0]=(que(now,1,j-1)+que(now,0,j-1))%mod;
			//printf("que(%d,%d):%d,que(%d,%d):%d\n",
				//	1,j-1,que(now,1,j-1),0,j-1,que(now,0,j-1));
			dp[i][j][1]=(que(now,1,maxm-1)-que(now,1,j)+mod)%mod;
			//printf("dp[%d][%d]:(%d,%d)\n",i,j,dp[i][j][0],dp[i][j][1]);
			_add(dp[i][j][1],dp[i-1][j][0]);
			//printf("dp[%d][%d]:(%d,%d)\n",i,j,dp[i][j][0],dp[i][j][1]);
			_add(dp[i][j][1],dp[i-1][j][1]);
			add(nxt,0,j,dp[i][j][0]);
			add(nxt,1,j,dp[i][j][1]);
			//printf("dp[%d][%d]:(%d,%d)\n",i,j,dp[i][j][0],dp[i][j][1]);
		}
		swap(now,nxt);
	}
	LL ans=0;
	for(int i=1;i<=up;i++) ans=(ans+dp[n][i][1])%mod;
	cout << ans << endl;
	return 0;
}

