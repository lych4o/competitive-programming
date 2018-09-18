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
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e3+10;

int n, m, a[maxn][maxn];
vector<int> v;
vector<pii> vp[maxn*maxn];
LL ans[maxn][maxn];

LL qpow(LL x, LL k){
    LL res = 1;
    while(k > 0){
        if(k&1) res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}

int main(){
    sc(n); sc(m);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        sc(a[i][j]); v.pb(a[i][j]);
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        int id = lower_bound(ALL(v), a[i][j])-v.begin();
        vp[id].pb(mk(i,j));
    }
    LL r1=0,c1=0,r2=0,c2=0,cnt=0,e=0;
    for(int id = 0; id < maxn*maxn; id++){
        for(auto now: vp[id]){
            LL r = now.fi, c = now.se;
            LL tmp = cnt*r*r + cnt*c*c + r2 + c2;
            tmp -= 2*r*r1 + 2*c*c1;
            tmp = ((tmp+e)%mod+mod)%mod;
            ans[r][c] = (tmp*qpow(cnt, mod-2)%mod + mod)%mod;
        }
        cnt += (LL)vp[id].size();
        for(auto now: vp[id]){
            LL r = now.fi, c = now.se;
            r1 += r; c1 += c;
            r2 += r*r; c2 += c*c;
            e += ans[r][c];
        }
        r1 %= mod; c1 %= mod;
        r2 %= mod; c2 %= mod; e %= mod;
    }
    int r,c; sc(r); sc(c);
    cout << (ans[r][c]+mod)%mod << endl;
    return 0;
}
