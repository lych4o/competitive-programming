#include<bits/stdc++.h>
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sll(x) scanf("%lld", &x)
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 1e3+10;

vector<int> v;
int id(int x){
    return lower_bound(ALL(v),x)-v.begin()+1;
}
LL bit[maxn], a[maxn], dp[maxn];
void add(int x, LL v){
    for(int i = x; i < maxn; i += i&-i){
        bit[i] += v;
        if(bit[i]>=mod) bit[i]-=mod;
    }
}
LL sum(int x){
    LL ret = 0;
    for(int i = x; i > 0; i -= i&-i){
        ret += bit[i];
        if(ret>=mod) ret -= mod;
    }
    return ret;   
}

int n, m, pos[maxn];

int main(){
    int T; cin >> T;
    for(int kase = 1; kase <= T; kase++){
        scanf("%d%d", &n,&m);
        v.clear();
        for(int i = 1; i <= n; i++) sll(a[i]), dp[i]=1, v.pb(a[i]);
        sort(ALL(v));
        v.erase(unique(ALL(v)),v.end());
        for(int i = 1; i <= n; i++){
            pos[i] = id(a[i]);
        }
        for(int j = 2; j <= m; j++){
            memset(bit,0,sizeof(bit));
            for(int i = 1; i <= n; i++){
                add(pos[i], dp[i]);
                dp[i] = sum(pos[i]-1);
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            ans += dp[i];
            if(ans >= mod) ans -= mod;
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
