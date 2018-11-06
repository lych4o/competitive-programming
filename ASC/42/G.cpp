#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;

vector<int> to[maxn];
int day[maxn], n, m, deg[maxn], emer[maxn], vis[maxn];
priority_queue<pii> q;

void dfs(int u){
    if(vis[u]) return;
    emer[u] = day[u]; vis[u]=1;
    for(int v: to[u]){
        dfs(v);
        emer[u] = min(emer[u],emer[v]-1);
    }
    //printf("emer[%d]:%d\n",u,emer[u]);
}
vector<int> ans;
int main(){
    freopen("grand.in","r",stdin);
    freopen("grand.out","w",stdout);
    while(sc(n)!=EOF){
        if(n==0) break;
        for(int i=1; i<=n; i++){
            ans.clear();
            day[i] = deg[i] = vis[i] = 0;
            to[i].clear();
            sc(day[i]);
        } 
        sc(m);
        for(int i=0; i<m; i++){
            int u, v; sc(u); sc(v);
            to[u].pb(v); deg[v]++;
        }
        while(q.size()) q.pop();
        for(int i=1; i<=n; i++){
            if(!vis[i]) dfs(i);
            if(deg[i]==0) q.push(mk(-emer[i],i));
        }
        int res = 0;
        while(q.size()){
            pii now = q.top(); q.pop();
            int u = now.se; ans.pb(u);
            res = max(res, max((int)ans.size()-day[u],0));
            for(int v: to[u]){
                deg[v]--; if(deg[v]==0) q.push(mk(-emer[v],v));
            }
        }
        printf("%d\n", res);
        for(int i = 0; i < (int)ans.size(); i++){
            printf("%d%c",ans[i]," \n"[i==(int)ans.size()-1]);
        }
    }
    return 0;
}
