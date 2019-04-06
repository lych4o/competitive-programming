#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const int maxn = 1e6+10;

int n, a[maxn], k, m;

int main(){
    sc(n); sc(m); sc(k);
    for(int i=0;i<n;i++) sc(a[i]);
    sort(a,a+n);
    LL ans = 0;
    int ep = k+1, t = m/ep;
    ans = t*(k*1LL*a[n-1] + a[n-2]) + m%ep*1LL*a[n-1];
    cout << ans << endl;
    return 0;
}
