#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
typedef long long LL;
int n, a[maxn];
int main(){
    cin >> n; for(int i=0;i<n;i++) cin>>a[i];
    LL ans=0;
    sort(a,a+n);
    for(int i=0,j=n-1;i<j;i++,j--){
        ans += 1LL*(a[i]+a[j])*(a[i]+a[j]);
    }
    cout << ans << endl;
    return 0;
}
