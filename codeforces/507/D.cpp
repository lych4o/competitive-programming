#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
using namespace std;
const int maxn = 1e5+10;
int n, dp[maxn], ans[maxn], res;
vector<int> to[maxn];
void dfs(int u, int f, int k){
	int mx1,mx2; mx1=mx2=0;
	for(int v: to[u])if(v!=f){
		dfs(v,u,k);
		if(dp[v]>mx1) mx2=mx1,mx1=dp[v];
		else mx2=max(mx2, dp[v]);
	}
	if(mx1+mx2+1>=k) dp[u]=0, res++;
	else dp[u]=mx1+1;
}
void solve(int a, int b, int L, int R){///[a,b],[L,R)
    if(a>b) return;
    if(L+1==R){
		for(int i=a;i<=b;i++) ans[i]=L;
        return ;
    }
    int m=(a+b)>>1; res=0; dfs(1,1,m); ans[m]=res;
    solve(a,m-1,res,R); solve(m+1,b,L,res+1);
}
int main(){
	sc(n);
	for(int i=1;i<n;i++){
		int u,v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	solve(1,n,0,n+1);
	for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
	return 0;
}
