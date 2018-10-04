#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define fi first
#define ALL(x) x.begin(), x.end()
#define se second
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;

int n, cnt[maxn][2], sz[maxn], d[maxn];
vector<int> to[maxn];
LL ans;

void dfs1(int u, int f){
    sz[u] = 1; d[u]=d[f]+1;
    for(int v: to[u]){
        if(v==f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int f, int res){
    if(u!=1){
        cnt[u][0]=cnt[f][1]; 
        cnt[u][1]=cnt[f][0];
    }
    ans += (res+cnt[u][1])/2;
    //printf("u:%d, res:%d, cnt[1]:%d, ans:%d\n",
      //      u,res,cnt[u][1],(res+cnt[u][1])/2);
    for(int v: to[u]){
        if(v==f) continue;
        int x = n-sz[v], y = sz[v];
        dfs2(v, u, res-y+x);
    }
}

int main(){
    sc(n);
    for(int i = 1; i < n; i++){
        int u, v; sc(u); sc(v);
        to[u].pb(v); to[v].pb(u);
    }
    d[0] = -1; dfs1(1,0);
    ans = 0;
    LL res = 0;
    for(int i = 1; i <= n; i++){
        cnt[1][d[i]%2]++;
        res += d[i];
    }
    dfs2(1,0,res);
    cout << ans/2 << endl;
    return 0;
}
