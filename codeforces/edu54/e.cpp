#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-8;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 3e5+10;
int n, m, d[maxn];
vector<int> to[maxn];
vector<pii> q[maxn];
LL ds[maxn], val[maxn];
void dfs(int u, int f, LL now){
	//printf("dfs(%d,%d,%I64d)\n",u,f,now);
	d[u]=d[f]+1;
	now -= ds[d[u]];
	for(pii p: q[u]){
		int	v=p.F, dd=min(p.S+d[u]+1,maxn-1);
		//printf("(%d,%d)\n",v,dd);
		ds[dd] += v;
		now += v;
	}
	val[u]=now;
	for(int v: to[u]) if(v!=f){
		dfs(v,u,now);
	}
	for(pii p: q[u]){
		int v=p.F, dd=min(p.S+d[u]+1,maxn-1);
		ds[dd] -= v;
	}
}
int main(){
	sc(n);
	for(int i=1;i<n;i++){
		int u,v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	sc(m);
	for(int i=0;i<m;i++){
		int v,dd,x; sc(x); sc(dd); sc(v);
		q[x].pb(mk(v,dd));
	}
	dfs(1,1,0);
	for(int i=1;i<=n;i++){
		printf("%I64d ", val[i]);
	}puts("");
	return 0;
}
