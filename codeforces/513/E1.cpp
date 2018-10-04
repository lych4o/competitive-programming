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
const int maxn = 1e3+10;

int n, cnt[maxn][2], sz[maxn], d[maxn][maxn];
vector<int> to[maxn];
LL ans;

int main(){
    sc(n);
    for(int i = 1; i < n; i++){
        int u, v; sc(u); sc(v);
        to[u].pb(v);
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
