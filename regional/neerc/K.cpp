#include<bits/stdc++.h>
#define debug puts("???")
#define pb push_back
#define sz(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e5+100;
vector<int> to[maxn], v, ans;
int nxt[maxn], n, m, num[maxn], vis[maxn], f[maxn], ed[maxn];
int Find(int x){
    if(f[x]==x) return x;
    return f[x]=Find(f[x]);
}
//nxt[x]=y
void print(){
    for(int i=1;i<=n;i++){
        printf("F[%d]:%d, nxt:%d, ed:%d\n",i,Find(i),nxt[i],ed[Find(i)]);
    }
}
inline void join(int x, int y){
    int fx=Find(x), fy=Find(y);
    f[fy] = fx; num[fx] += num[fy];
}
int get(int x){
    if(ed[x]) x = ed[x];
    return Find(nxt[x]);
}
void get_ans(){
    ans.clear(); ans.pb(1);
    for(int i=nxt[1];i!=1;i=nxt[i]) ans.pb(i);
    ans.pb(1);
}
void dfs(int x){
    if(x>=sz(v)){
        printf("dfs:\n");
        print();
        int bg = Find(1), sum = num[bg], u = get(bg);
        while(u!=bg && u){
            //printf("u:%d, nxt:%d\n",u,get(u));
            u = Find(u);
            sum += num[u];
            u = get(u);
        }
        if(sum==n) get_ans();
        return;
    }
    int u = v[x];
    for(int v: to[u]) if(!vis[v]){
        nxt[u]=v;
        vis[u]=vis[v]=1;
        dfs(x+1);
        vis[u]=vis[v]=0;
    }
}
int solve(){
    for(int i=1;i<=n;i++) f[i]=i,num[i]=1;
    for(int i=1;i<=n;i++){
        if(sz(to[i])==0) return 0;
        if(sz(to[i])==1) join(i,to[i][0]),nxt[i]=to[i][0];
        else v.pb(i);
    }
    for(int i=1;i<=n;i++) if(!vis[i]){
        int hd = Find(i), u = hd;
        while(nxt[u]){
            u = nxt[u];
            vis[u]=1;
        }
        ed[hd]=u; vis[hd]=0;
    }
    print();
    dfs(0);
    return sz(ans);
}
int main(){
#ifndef LYCH
    freopen("king.in","r",stdin);
    freopen("king.out","w",stdout);
#endif
    sc(n); sc(m);
    for(int i=0;i<m;i++){
        int u,v; sc(u); sc(v);
        if(u==v) continue;
        to[u].pb(v);
    }
    if(!solve()) puts("There is no route, Karl!");
    else{
        for(int i=0;i<=n;i++) printf("%d%c",ans[i],(i==n)?'\n':' ');
    }
    return 0;
}
