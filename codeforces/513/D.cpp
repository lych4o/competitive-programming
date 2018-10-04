#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
int n, l[maxn], r[maxn];

vector<int> vl, vr;
int main(){
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(l[i]); sc(r[i]);
        vl.pb(l[i]); vr.pb(r[i]);
    }
    LL ans = 0;
    sort(vl.begin(),vl.end()); sort(vr.begin(),vr.end());
    for(int i = 0; i < (int)vl.size(); i++){
        ans += max(vl[i],vr[i]);
    }
    cout << ans+n << endl;
    return 0;
}
