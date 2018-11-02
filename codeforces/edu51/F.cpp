#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#define pii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define debug puts("???");
#define br puts("")
#define ALL(x) x.begin(),x.end()
#define sc(x) scanf("%d", &x)
#define sz(x) int((x).size())
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

const int maxn = 1e5+10;
struct edge{
    int u,v,d;
    edge(int u=0, int v=0, int d=0):u(u),v(v),d(d){}
};
vector<edge> to[maxn];
vector<edge> vp;
int func[maxn], f[maxn][20], dep[maxn], n, m;
LL path[maxn];
int Find(int x){return x==func[x]?x:func[x]=Find(func[x]);}
void dfs(int u, int fa, int len){
    f[u][0] = fa;
    dep[u]=dep[fa]+1;
    path[u]=path[fa]+len;
    //printf("dfs(%d,%d,%d):%d\n",u,fa,len,path[u]);
    for(edge e: to[u]){
        if(e.v==fa) continue;
        dfs(e.v,u,e.d);
    }
}
void lca_init(){
    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            f[i][j] = f[f[i][j-1]][j-1];
        }
    }
}
inline int lca(int u, int v){
    //printf("lca(%d,%d)\n",u,v);
    if(dep[u]<dep[v]) swap(u,v);
    for(int i = 19; i >= 0; i--){
        if(dep[u]-(1<<i) >= dep[v]) u = f[u][i];
    }
    //printf("u:%d, v:%d\n",u,v);
    for(int i = 19; i >= 0; i--){
        if(f[u][i]==f[v][i]) continue;
        u=f[u][i], v=f[v][i];
    }
    if(u==v) return u;
    return f[u][0];
}
inline LL dis(int u, int v){ return path[u]+path[v]-2*path[lca(u,v)];}
int vis[maxn], pnt[50];
LL d[50][50], pnum=0, dd[maxn][50];
void floyd(){
    for(edge e: vp){
        int u=e.u, v=e.v;
        if(!vis[u]) pnt[++pnum]=u, vis[u]=pnum;
        if(!vis[v]) pnt[++pnum]=v, vis[v]=pnum;
        d[vis[u]][vis[v]]=d[vis[v]][vis[u]]=e.d;
    }
    //for(int i=1; i<=pnum; i++) printf("%d ", pnt[i]); puts("");
    for(int i = 1; i <= pnum; i++) for(int j = 1; j <= pnum; j++){
        if(d[i][j]==0 && i!=j) d[i][j]=INF64;
        d[i][j] = min(d[i][j], dis(pnt[i],pnt[j]));
    }
    for(int k=1; k<=pnum; k++) for(int i=1; i<=pnum; i++) for(int j=1; j <=pnum; j++){
        if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=pnum; j++){
        dd[i][j] = dis(i,pnt[j]);
        //if(vis[i]) dd[i][j]=min(dd[i][j],d[vis[i]][j]);
        //printf("dd[%d][%d]:%I64d\n",i,pnt[j],dd[i][j]);
    }
}
void DEBUG(){
    int u, v;
    while(cin >> u >> v){
        printf("(%d,%d):path:(%I64d,%I64d), lca:%d, dis:%I64d\n",
        u,v,path[u],path[v],lca(u,v),dis(u,v));
    }
}
int main(){
    sc(n); sc(m);
    for(int i = 1; i <= n; i++) func[i]=i;
    for(int i = 0; i < m; i++){
        int u, v, d; sc(u); sc(v); sc(d);
        int fu = Find(u), fv = Find(v);
        if(fu==fv) vp.pb(edge(u,v,d));
        else func[fu]=fv, to[u].pb(edge(u,v,d)), to[v].pb(edge(v,u,d));
    }
    dfs(1,0,0);
    lca_init();
    floyd();
    //DEBUG();
    int q; sc(q);
    while(q--){
        int u, v; sc(u); sc(v);
        LL ans = dis(u,v);
        //printf("ans:%I64d\n", ans);
        for(int i=1; i<=pnum; i++) for(int j=1; j<=pnum; j++){
            LL tmp = dd[u][i]+dd[v][j];
            //printf("dd[%d][%d]:%I64d, dd[%d][%d]:%I64d, d[%d][%d]:%I64d\n",
            //u,pnt[i],dd[u][i],v,pnt[j],dd[v][j],pnt[i],pnt[j],d[i][j]);
            ans = min(ans, tmp+d[i][j]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}


