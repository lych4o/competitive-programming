#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5+10;
struct edge
{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w):u(u), v(v), w(w){}
}es[maxn], tb[maxn];
vector<pii> G[2][maxn];
ll dist[2][maxn];
int head[maxn], pre[maxn], dfn[maxn], low[maxn];
bool cut[maxn], tag[maxn];
int n, m, idx;

void dijkstra(int s, int t)
{
	for(int i = 1; i <= n; i++)dist[t][i] = INF64;
	dist[t][s] = 0;
	priority_queue<pli, vector<pli>, greater<pli> > pq;
	pq.push(mk(dist[t][s], s));
	while(!pq.empty()){
		pli p = pq.top(); pq.pop();
		if(p.fi != dist[t][p.se])continue;
		for(auto v : G[t][p.se]){
			if(dist[t][v.fi] > dist[t][p.se]+v.se){
				dist[t][v.fi] = dist[t][p.se]+v.se;
				pq.push(mk(dist[t][v.fi], v.fi));
			}
		}
	}
}

void add_edge(int u, int v, int id)
{
	es[id<<1] = edge(u, v, head[u]);
	head[u] = id<<1;
	es[id<<1|1] = edge(v, u, head[v]);
	head[v] = id<<1|1;
}

void dfs(int u, int f)
{
	dfn[u] = low[u] = ++idx;
	for(int i = head[u]; ~i; i = es[i].w){
		int v = es[i].v;
		if(v == f)continue;
		if(!dfn[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u])cut[i>>1] = 1;
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

void dfs1(int u)
{
	dfn[u] = idx;
	for(int i = head[u]; ~i; i = es[i].w){
		if(cut[i>>1] || dfn[es[i].v])continue;
		dfs1(es[i].v);
	}
}


void tarjan()
{
	for(int i = 1; i <= n; i++){
		if(!dfn[i])dfs(i, 0);
	}
	idx = 0;
	for(int i = 1; i <= n; i++)dfn[i] = 0;
	for(int i = 1; i <= n; i++){
		if(!dfn[i])++idx, dfs1(i);
	}
}

void dfs2(int u, int f)
{
	pre[u] = f;
	for(int i = head[u]; ~i; i = es[i].w){
		int v = es[i].v;
		if(v == f)continue;
		dfs2(v, u);
	}
}

void build()
{
	for(int i = 1; i <= idx; i++)head[i] = -1;
	for(int i = 1; i <= m; i++){
		int u = tb[i].u, v = tb[i].v;
		if(cut[i]){
			add_edge(dfn[u], dfn[v], i);
		}
	}
	dfs2(1, 0);
	for(int i = 1;  i <= m; i++){
		int u = tb[i].u, v = tb[i].v;
		if(dfn[u] != dfn[v] && pre[dfn[v]] == dfn[u])tag[i] = 1;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		tb[i] = edge(u, v, w);
		G[0][u].pb(mk(v, w));
		G[1][v].pb(mk(u, w));
	}
	dijkstra(1, 0);
	dijkstra(2, 1);
	for(int i = 1; i <= n; i++)head[i] = -1;
	for(int i = 1; i <= m; i++){
		int u = tb[i].u, v = tb[i].v, w = tb[i].w;
		if(dist[0][u]+w+dist[1][v] == dist[0][2]){
			add_edge(u, v, i);
		}
	}
	tarjan();
	build();
	for(int i = 1; i <= m; i++){
		int u = tb[i].u, v = tb[i].v, w = tb[i].w;
		if(dist[0][v]+w+dist[1][u] < dist[0][2])puts("HAPPY");
		else{
			if(!tag[i] || !cut[i])puts("SOSO");
			else puts("SAD");
		}
	}
	return 0;
}
