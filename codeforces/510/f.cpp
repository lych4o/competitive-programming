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
#define sz(x) int(x.size())
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e6+10;

vector<int> to[maxn];
int n, k, ans;

int dfs(int u, int p){
    if(sz(to[u]) == 1) return 0;
    vector<int> cur;
    for(auto v: to[u]){
        if(v==p) continue;
        cur.pb(dfs(v,u)+1);
    }
    sort(ALL(cur));
    while(sz(cur) >= 2){
        if(cur[sz(cur)-1]+cur[sz(cur)-2] <= k) break;
        ans++;
        cur.pop_back();
    }
    return cur.back();
}

int main(){
    sc(n); sc(k);
    for(int i = 1; i < n; i++){
        int u, v; sc(u); sc(v);
        to[u].pb(v); to[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(to[i].size() > 1){
            dfs(i,i);
            break;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
