#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const LL INF = 10;
//const LL INF = 0x3f3f3f3f;
const int maxn = 1510;

int a[maxn], n, m, s, k, sum[maxn],
	dp[maxn][maxn], r[maxn];

int check(LL mid){
	//printf("check(%lld):\n",mid);
	for(int i=1;i<=n;i++) sum[i]=(a[i]<=mid)+sum[i-1];
	//for(int i=1;i<=n;i++) printf("%lld ", sum[i]); puts("");
	memset(dp,0,sizeof(dp));
	int mx=0;
    for(int i=0;i<=n;i++) for(int j=0;j<=s;j++){
		dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
		//printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
		if(r[i+1]>i){
			int R=r[i+1];
			//printf("R:%d, dp=%d+%d-%d=%d\n",
			//		R,dp[i][j],sum[R],sum[i],dp[i][j]+sum[R]-sum[i]);
			dp[R][j+1]=max(dp[R][j+1],dp[i][j]+sum[R]-sum[i]);
		}
		mx=max(mx,dp[i][j]);
    }
    return mx;
}
int main(){
	sc(n); sc(m); sc(s); sc(k);
	for(int i=1;i<=n;i++) sc(a[i]);
	for(int i=0;i<m;i++){
		int L, R; sc(L); sc(R);
		r[L] = max(r[L], R);
	}
	for(int i=1;i<=n;i++) r[i]=max(r[i],r[i-1]);
	//for(int i=1;i<=n;i++) printf("r[%d]:%d\n",i,r[i]);
	//check(1);
    LL L=0,R=INF;
    while(L+1<R){
		LL mid = (L+R)>>1;
		if(check(mid)>=k) R=mid;
		else L = mid;
    }
    if(R==INF) printf("-1\n");
    else cout << R << endl;
	return 0;
}
