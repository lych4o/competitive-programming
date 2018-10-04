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
const int maxn = 2e3+10;
vector<LL> val;
LL a[maxn], b[maxn], sa[maxn], up, sb[maxn], len[maxn*maxn];
int n, m;

inline int id(LL x){
    return lower_bound(ALL(val),x)-val.begin();
}
int main(){
    sc(n); sc(m);
    sa[0]=sb[0]=0;
    for(int i = 1; i <= n; i++) sll(a[i]), sa[i]=sa[i-1]+a[i];
    for(int i = 1; i <= m; i++) sll(b[i]), sb[i]=sb[i-1]+b[i];
    sll(up);
    LL ans = 0; val.clear();
    for(int i=1;i<=m;i++) for(int j=i;j<=m;j++){
        LL x = sb[j]-sb[i-1];
        len[x] = max(len[x],j-i+1LL);
    }
    for(int i = 1; i < maxn*maxn; i++){
        len[i] = max(len[i],len[i-1]);
    }
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
        LL x = sa[j]-sa[i-1]; x = up/x;
        if(x >= maxn*maxn) x = maxn*maxn-1;
        //printf("a[%d,%d]:%lld, %lld, p:%d\n",i,j,sa[j]-sa[i-1],x,p);
        ans = max(ans,(j-i+1)*1LL*len[x]);
    }
    cout << ans << endl;
    return 0;
}
