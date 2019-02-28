#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
using namespace std;
const int maxn = 1e5+10;
vector<int> to[maxn];
int n, m, vis[maxn];
priority_queue<int> q;
vector<int> ans;
int main(){
    sc(n); sc(m);
    for(int i=0;i<m;i++){
        int u, v; sc(u); sc(v);
        to[u].pb(v); to[v].pb(u);
    }
    q.push(-1); vis[1]=1;
    while(q.size()){
        int u = -q.top(); q.pop();
        ans.pb(u);
        for(int v: to[u]){
            if(!vis[v]) q.push(-v), vis[v]=1;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d%c",ans[i],i==n-1 ? '\n':' ');
    }
    return 0;
}
