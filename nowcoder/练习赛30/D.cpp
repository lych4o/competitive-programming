#include<bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d", &x)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+10;
vector<int> G[maxn];
int mtx[maxn], mty[maxn], dx[maxn], dy[maxn];
bool vis[maxn], vx[maxn], vy[maxn];
int dis, uN, vN;
bool bfs()
{
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    queue<int> q;
    for(int i = 1; i <= uN; i++){
        if(!mtx[i])q.push(i), dx[i] = 0;
    }
    while(!q.empty()){
        assert(q.size() < 1e4);
        int u = q.front(); q.pop();
        if(dx[u] > dis)break;
        for(auto v : G[u]){
            if(dy[v] == -1){
                dy[v] = dx[u]+1;
                if(!mty[v])dis = dy[v];
                else{
                    dx[mty[v]] = dy[v]+1;
                    q.push(mty[v]);
                }
            }
        }
    }
    return dis < INF;
}
bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v] && dy[v] == dx[u]+1){
            if(dy[v] == dis && mty[v])continue;
            if(!mty[v] || dfs(mty[v])){
                mty[v] = u, mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
 
bool get_ans(int u)
{
    vx[u] = 1;
    for(auto v : G[u]){
        if(!vy[v]){
            vy[v] = 1;
            if(!mty[v] || get_ans(mty[v])){
                mty[v] = u, mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int max_match()
{
    int ret = 0;
    /*while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= uN; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }*/
    for(int i = 1; i <= uN; i++){
        memset(vx, 0, sizeof(vx));
        memset(vy, 0, sizeof(vy));
        if(get_ans(i))ret++;
    }
    memset(vx, 0, sizeof(vx));
    memset(vy, 0, sizeof(vy));
    for(int i = 1; i <= uN; i++){
        if(!mtx[i])get_ans(i);
    }
    return ret;
}
 
char s[maxn];
int main(){
    sc(uN); sc(vN);
    for(int i=1;i<=uN;i++){
        scanf("%s", s+1);
        for(int j=1;j<=vN;j++){
            if(s[j]=='*') G[i].pb(j);
        }
    }
    int ans=max_match();
    printf("%d\n", ans);
    vector<int> vec;
    for(int i = 1; i <= uN; i++){
        if(!vx[i])vec.pb(i);
    }
    printf("%lu%c", vec.size(), " \n"[vec.size()==0]);
    for(int i = 0; i < (int)vec.size(); i++){
        printf("%d%c", vec[i], " \n"[i==(int)vec.size()-1]);
    }
    vec.clear();
    for(int i = 1; i <= vN; i++){
        if(vy[i])vec.pb(i);
    }
    printf("%lu%c", vec.size(), " \n"[vec.size()==0]);
    for(int i = 0; i < (int)vec.size(); i++){
        printf("%d%c", vec[i], " \n"[i==(int)vec.size()-1]);
    }
    return 0;
}
