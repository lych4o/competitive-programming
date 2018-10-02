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
#define sll(x) scanf("%I64d", &x)
#define sz(x) int((x).size())
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e5+10;

int n;
LL u, e[maxn];

int main(){
    sc(n); sll(u);
    double ans = 0;
    for(int i = 1; i <= n; i++) sll(e[i]);
    for(int i=1,j=1; i<=n; i++){
        while(j<=n && e[j]-e[i]<=u) j++;
        if(j==i+1) continue;
        //printf("e[%d]:%I64d, e[%d]:%I64d, e[%d]:%I64d\n",
            //j-1,e[j-1],i+1,e[i+1],i,e[i]);
        ans = max(ans, 1.0*(e[j-1]-e[i+1])/(e[j-1]-e[i]));
    }
    if(ans == 0) puts("-1");
    else printf("%.10f\n",ans);
    return 0;
}
