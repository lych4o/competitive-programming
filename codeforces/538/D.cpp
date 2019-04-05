#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 5e3+10;
int dp[maxn][maxn], n, c[maxn], m;
int solve(int l, int r){
	//printf("solve(%d,%d)\n",l,r);
	if(dp[l][r]>=0) return dp[l][r];
	if(l>=r) return dp[l][r]=0;
	dp[l][r] = min(solve(l+1,r)+1,solve(l,r-1)+1);
	if(c[l]==c[r]) dp[l][r] = min(dp[l][r], solve(l+1,r-1)+1);
	return dp[l][r];
}
int main(){
	sc(m); n=0;
	int pre = -1;
	for(int i=0;i<m;i++){
		sc(c[n]); if(c[n]==pre) continue;
		pre=c[n++];
	}
	//for(int i=0;i<n;i++) printf("c[%d]:%d\n",i,c[i]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(0,n-1));
	return 0;
}
