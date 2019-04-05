#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
using namespace std;
typedef double db;
const int maxn = 1e5+10;
vector<int> to[maxn];
int dis[maxn], n, fa[maxn];
db s;
void dfs(int u, int f=0){
	dis[u]=dis[f]+1; fa[u]=f;
	for(int v: to[u]) if(v!=f) dfs(v,u);
}
int get(){
	int mx=-1, p;
	for(int i=1;i<=n;i++) if(dis[i]>mx) p=i,mx=dis[i];
	return p;
}

int main(){
	sc(n);
	cin >> s;
	for(int i=1;i<n;i++){
		int u,v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	int a,b;
	dfs(1); a = get();
	dfs(a); b = get();
	int cnt = 0;
	b = fa[b];
	while(b!=a){
		cnt += to[b].size()-2;
		b = fa[b];
	}
	printf("%.8f\n", s*2.0/(cnt+2));
	return 0;
}
