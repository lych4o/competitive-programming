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
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

int n;
LL a[maxn], t;
vector<LL> v;

inline int id(LL x){
    return lower_bound(ALL(v),x)-v.begin()+1;
}
int bit[maxn];
inline int lowbit(int x){return x&-x;}
void add(int x){
    for(int i = x; i < maxn; i += lowbit(i))
        bit[i]++;
}
int sum(int x){
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        ret += bit[i];
    return ret;
}
int main(){
    sc(n); cin >> t; v.pb(0);
    for(int i = 1; i <= n; i++){
        scanf("%I64d", &a[i]);
        a[i] += a[i-1];
        v.pb(a[i]);
    }
    sort(ALL(v));
    //for(int i = 0; i < (int)v.size(); i++) printf("%I64d ", v[i]);
    //puts("");
    LL ans = 0;
    add(id(0));
    for(int i = 1; i <= n; i++){
        int x = id(a[i]-t+1);
        //printf("a[%d]:%I64d, b:%I64d, x:%d\n",i,a[i],a[i]-t+1,x);
        ans += sum(maxn-1) - sum(x-1);
        add(id(a[i]));
    }
    cout << ans << endl;
    return 0;
}
