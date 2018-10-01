#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
const int BITNUM = 63;
LL b[BITNUM];
void Insert(LL x){
    //printf("Insert(%lld)\n",x);
    for(int i=BITNUM-1;i>=0;i--){
        if(!(x>>i&1)) continue;
        if(b[i]) x ^= b[i];
        else{
            b[i] = x;
            for(int j=i-1; j>=0; j--)
                if(b[j]&&(b[i]>>j&1)) b[i] ^= b[j];
            for(int j=i+1; j<BITNUM; j++)
                if(b[j]>>i&1) b[j] ^= b[i];
            break;
        }
    }
}
LL get_max(){
    LL ret = 0;
    for(int i=0; i<BITNUM; i++) ret ^= b[i];
    return ret;
}
const int maxn = 5e4+10;

vector<pair<int,LL>> to[maxn];
int n, m, vis[maxn];
LL val[maxn];

void dfs(int u){
    //printf("dfs(%d):%lld\n",u,val[u]);
    vis[u] = 1;
    for(auto e: to[u]){
        int v = e.fi; LL w = e.se;
        if(vis[v]) Insert(val[u]^val[v]^w);
        else{
            val[v] = val[u]^w;
            dfs(v);
        }
    }
}
int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); sc(m);
        for(int i=1; i<=n; i++) to[i].clear(), val[i]=vis[i]=0;
        memset(b, 0, sizeof(b));
        for(int i=0; i<m; i++){
            int u,v; LL w; sc(u); sc(v); sll(w);
            to[u].pb(mk(v,w)); to[v].pb(mk(u,w));
        }
        dfs(1);
        printf("Case #%d: %lld\n", kase, get_max());
    }
    return 0;
}
