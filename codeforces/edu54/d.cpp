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
#define pLL pair<LL, LL>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-8;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 3e5+10;

vector<int> ans;
int tot,to[maxn*2],head[maxn],nxt[maxn*2];
LL cost[maxn], val[maxn*2];
void add_edge(int u, int v, int w){
	to[++tot]=v; nxt[tot]=head[u]; head[u]=tot; val[tot]=w;
	to[++tot]=u; nxt[tot]=head[v]; head[v]=tot; val[tot]=w;
}
void dijkstra(int s, int k){
	memset(cost, 0x3f, sizeof(cost));
	cost[s]=0;
	priority_queue<pLL, vector<pLL>, greater<pLL> > pq;
	to[0]=s; 
	pq.push(mk(0LL,0LL));
	while(!pq.empty() && k){
        pLL p = pq.top(); pq.pop();
		int u=to[p.S];
        if(cost[u] < p.F)continue;
		//printf("(%d,%d):u:%d\n",p.F,p.S,u);
		if(p.S>0) ans.pb((p.S+1)/2), k--;
		for(int i=head[u];i;i=nxt[i]){
			if(cost[to[i]]>cost[u]+val[i]){
				cost[to[i]]=cost[u]+val[i];
				pq.push(mk(1LL*cost[to[i]], 1LL*i));
				//printf("cost[%d]:%lld,(%lld,%lld)\n",
					//	to[i],cost[to[i]],cost[to[i]],1LL*i);
			}
		}
        /*for(auto v : G[p.se]){
            if(cost[v.fi] > cost[p.se]+v.se){
                cost[v.fi] = cost[p.se]+v.se;
                pq.push(mk(cost[v.fi], v.fi));
            }
        }*/
	}
}
int n,m,k;
int main(){
	sc(n); sc(m); sc(k); tot=0;
	for(int i=0;i<m;i++){
		int u,v,w; sc(u); sc(v); sc(w);
		add_edge(u,v,w);
	}
	dijkstra(1,k);
	printf("%d\n",SZ(ans));
	for(int i: ans) printf("%d ", i);
	puts("");
	return 0;
}
