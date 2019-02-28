#include<bits/stdc++.h>
#define debug puts("???"), fflush(stdout)
#define pb push_back
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 1e5+10;
struct hh{
    int w,d,id;
    hh(int w=0,int d=0,int id=0):w(w),d(d),id(id){}
    bool operator < (const hh& r) const {
        if(w!=r.w) return w<r.w;
        if(d!=r.d) return d<r.d;
        return id<r.id;
    }
};
set<hh> st;
int n, m, s[maxn], t[maxn], d[maxn], w[maxn],
    chs[maxn], nxt[maxn], k;
LL dp[maxn][205];
vector<pii> v;

LL solve(int p, int x){
    //printf("(%d,%d)\n",p,x);
    if(p>n) return dp[p][x] = 0;
    if(dp[p][x]>=0) return dp[p][x];
    if(!chs[p]){
        dp[p][x] = solve(p+1,x);
        return dp[p][x];
    }
    int u = chs[p];
    dp[p][x] = w[u] + solve(d[u]+1, x);
    if(x-nxt[p]+p-1 >= 0){
        dp[p][x] = min(dp[p][x], solve(nxt[p]+1,x-nxt[p]+p-1));
    }
    return dp[p][x];
}
int main(){
    memset(dp,-1,sizeof(dp));
    sc(n); sc(m); sc(k);
    for(int i=1;i<=k;i++){
        sc(s[i]),sc(t[i]),sc(d[i]),sc(w[i]);
        v.pb(mk(s[i],i));
        v.pb(mk(t[i]+1,-i));
    }
    sort(v.begin(), v.end());
    for(int i=1, j=0;i<=n;i++){
        while(v[j].F<=i && j<(int)v.size()){
            int x=v[j].F, y=v[j].S;
            if(y<0){
                y *= -1;
                st.erase(hh(w[y],d[y],y));
            }else{
                st.insert(hh(w[y],d[y],y));
            }
            j++;
        }
        if((int)st.size()>0) chs[i] = (st.rbegin())->id;
        //printf("%d ", chs[i]);
    } //puts("");
    for(int i=n, j;i>=1;i=j){
        for(j=i;j>=1&&chs[j]==chs[i];j--) nxt[j]=i;
    }
    //for(int i=1;i<=n;i++) printf("%d ", nxt[i]); puts("");
    printf("%lld\n", solve(1,m));
    return 0;
}
