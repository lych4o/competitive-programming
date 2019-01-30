#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
LL a[maxn], n, k;
string s;
vector<LL> v;
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> s;
    LL ans = 0;
    for(int i=0,j;i<n;i=j){
        for(j=i, v.clear();s[j]==s[i];j++) v.pb(a[j]);
        sort(v.begin(), v.end());
        for(int p=j-i-1;p>=max(j-i-k, 0LL);p--) ans += v[p];
    }
    cout << ans << endl;
    return 0;
}
