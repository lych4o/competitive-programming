#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const int maxn = 1e4+10;
vector<pii> e[maxn];
int n, sz[maxn], mx[maxn], ms, rt;
LL dis[2], ans;
bool vis[maxn];
void dfs_size(int u, int f){
    sz[u]=1; mx[u]=0;
    for(auto p: e[u]) if(p.F != f && !vis[p.F]){
        dfs_size(p.F, u);
        sz[u] += sz[p.F];
        if(sz[p.F] > mx[u]) mx[u] = sz[p.F];
    }
}
void dfs_root(int r, int u, int f){
    if(sz[r]-sz[u]>mx[u]) mx[u]=sz[r]-sz[u];
    if(mx[u]<ms) ms=mx[u], rt=u;
    for(auto p: e[u]) if(p.F!=f && !vis[p.F]){
        dfs_root(r, p.F, u);
    }
}
void dfs_dis(int u, int f, int d){
    dis[d]++;
    for(auto p: e[u]) if(p.F!=f&&!vis[p.F]){
        dfs_dis(p.F, u, d^p.S);
    }
}
LL solve(int u){
    dis[0]=dis[1]=0;
    dfs_dis(u, 0, 0);
    LL ret=0,d0=dis[0],d1=dis[1];
    ret += d0*d0*d0;
    ret += d1*d1*d1;
    return ret;
}
void dfs(int u){
    ms = n;
    dfs_size(u,0); dfs_root(u,u,0);
    ans += solve(rt);
    vis[rt]=1;
    int pnt = rt;
    for(auto p: e[pnt]) if(!vis[p.F]){
        ans -= solve(p.F);
        dfs(p.F);     
    }
}
int main(){
    sc(n);
    for(int i=1;i<n;i++){
        int u,v,d;
        sc(u); sc(v); sc(d); d%=2;
        e[u].pb(mk(v,d)); e[v].pb(mk(u,d));
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
