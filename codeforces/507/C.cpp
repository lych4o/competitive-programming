#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pLL pair<LL, LL>
#define pb push_back
#define mk make_pair
#define sp putchar(' ')
#define ln puts("")
#define fi first
#define fout fflush(stdout)
#define sqr(x) ((x)*(x))
#define ALL(x) x.begin(), x.end()
#define se second
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 5e5+10;

int f[maxn], u[maxn], v[maxn];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
void join(int x,int y){int fx=Find(x),fy=Find(y);f[fx]=fy;}
map<LL, vector<int>> mp;
set<int> st, p;
int n, m, k;
LL w[maxn], pw[maxn];
int main(){
    sc(n); sc(m); sc(k);
    pw[0] = 1;
    for(int i=1;i<=n;i++) sll(w[i]), f[i]=i, pw[i]=pw[i-1]*2%mod;
    for(int i=0;i<m;i++){
        sc(u[i]); sc(v[i]);
        LL x = w[u[i]]^w[v[i]];
        if(x < (1LL<<k)) mp[x].pb(i);
    }
    LL ans = 0;
    for(auto pv: mp){
        p.clear(); st.clear();
        for(int i: pv.se){
            p.insert(u[i]); p.insert(v[i]);
            join(u[i],v[i]);
        }
        for(int x: p) st.insert(Find(x));
        for(int i: pv.se) f[u[i]]=u[i],f[v[i]]=v[i];
        ans += pw[n-p.size()+st.size()];
    }
    ans += ((1LL<<k)-mp.size())%mod*pw[n];
    cout << ans%mod << endl;
    return 0;
}
