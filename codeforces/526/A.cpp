#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define sc(x) scanf("%d",&x)
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int maxn = 3e5+10;
int n, w[maxn];
vector<pii> to[maxn];
LL ans = 0, dp[maxn];
void dfs(int u, int f){
	ans = max(ans, 1LL*w[u]);
	dp[u] = w[u];
	for(pii nxt: to[u]){
		int v=nxt.F, c=nxt.S;
		if(v==f) continue;
		dfs(v, u);
		ans = max(ans, dp[u]+dp[v]-c);
		dp[u] = max(dp[u], dp[v]+w[u]-c);
	}
}
int main(){
	sc(n);
	for(int i=1;i<=n;i++) sc(w[i]);
	for(int i=1;i<n;i++){
		int u, v, c; sc(u); sc(v); sc(c);
		to[u].pb(mk(v,c));
		to[v].pb(mk(u,c));
	}
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
