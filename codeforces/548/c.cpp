#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const LL mod = 1e9+7;
const int maxn = 1e5+10, maxk = 105;

const int maxc = 1e6+10;
int FAC[maxc], IVF[maxc], IV[maxc];
void init(){
    IV[1] = FAC[0] = FAC[1] = IVF[0] = IVF[1] = 1;
    for(int i = 2; i < maxc; i++){
        FAC[i] = 1LL*FAC[i-1]*i%mod;
        IV[i] = 1LL*(mod-mod/i)*IV[mod%i]%mod;
        IVF[i] = 1LL*IVF[i-1]*IV[i]%mod;
    }
}
LL comb(int x, int y){
    if(x < y) swap(x,y);
    return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;
}

LL f[maxn], dp[maxk][maxn];
vector<pii> to[maxn]; 
vector<int> vi;
int n, k, vis[maxn];

void dfs(int u, int f){
    vi.pb(u); vis[u]=1;
    for(pii nxt: to[u]) if(nxt.F != f){
        int v = nxt.F, w = nxt.S;
        if(w) continue;
        dfs(v, u);
    }
}

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k>0){
        if(k&1) ret = ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
int main(){
	init();
    sc(n); sc(k);
    for(int i=1;i<n;i++){
        int u, v, w; sc(u); sc(v); sc(w);
        to[u].pb(mk(v,w)); to[v].pb(mk(u,w));
    }
    LL ans = 0;
    for(int i=1;i<=n;i++) if(!vis[i]){
        dfs(i, i);
        //printf("%d, %d\n",i,(int)vi.size());
        ans += qpow((int)vi.size(), k);
        vi.clear();
    }
    ans %= mod;
    cout << (qpow(n,k)-ans+mod)%mod << endl;
    return 0;
}
