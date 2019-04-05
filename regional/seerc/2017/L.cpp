#include<bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+10;
struct tr{
	vector<int> to[maxn];
	int f[maxn][20], flg, dep[maxn], n, cnt[maxn];
	tr(){
		flg=dep[0]=0;
		memset(cnt,0,sizeof(cnt));
	}
	void dfs(int u, int fa=0){
		f[u][0]=fa; dep[u]=dep[fa]+1;
		for(int v: to[u]) if(v!=fa) dfs(v,u);
	}
	void dfs_cnt(int u, int fa=0){
		for(int v: to[u]) if(v!=fa){
			dfs_cnt(v,u);
			cnt[u] += cnt[v];
		}
	}
	void lca_init(){
		for(int h=1;(1<<h)<=n;h++) for(int u=1;u<=n;u++){
			f[u][h]=f[f[u][h-1]][h-1];
		}
		flg=1;
	}
	int lca(int u, int v){
		if(!flg) lca_init();
		if(dep[u]<dep[v]) swap(u,v);
		for(int h=19;h>=0;h--)
			if(dep[f[u][h]]>=dep[v]) u = f[u][h];
		if(u==v) return u;
		for(int h=19;h>=0;h--)
			if(f[u][h]!=f[v][h]) u=f[u][h],v=f[v][h];
		return f[u][0];
	}
} a, b;
int n;
int main(){
	sc(n); a.n=b.n=n;
	for(int i=1;i<n;i++){
		int u,v; sc(u); sc(v);
		a.to[u].pb(v); a.to[v].pb(u);
	}
	for(int i=1;i<n;i++){
		int u,v; sc(u); sc(v);
		b.to[u].pb(v); b.to[v].pb(u);
	}
	a.dfs(1); b.dfs(1);
	for(int u=1;u<=n;u++){
		for(int v: a.to[u]) if(v>u){
			//printf("b.lca(%d,%d):%d\n",u,v,b.lca(u,v));
			b.cnt[u]++; b.cnt[v]++;
			b.cnt[b.lca(u,v)] -= 2;
		}
		for(int v: b.to[u]) if(v>u){
			//printf("a.lca(%d,%d):%d\n",u,v,a.lca(u,v));
			a.cnt[u]++; a.cnt[v]++;
			a.cnt[a.lca(u,v)] -= 2;
		}
	}
	a.dfs_cnt(1); b.dfs_cnt(1);
	int ans=n,tot=0;
	for(int i=2;i<=n;i++){
		if(a.cnt[i]+1<ans) ans=a.cnt[i]+1,tot=1;
		else if(a.cnt[i]+1==ans) tot++;
	}
	for(int i=2;i<=n;i++){
		if(b.cnt[i]+1<ans) ans=b.cnt[i]+1,tot=1;
		else if(b.cnt[i]+1==ans) tot++;
	}
	if(ans==2) tot/=2;
	printf("%d %d\n",ans,tot);
	return 0;
}
