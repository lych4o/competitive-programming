#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e3+10;
typedef long long LL;

int a[maxn];
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    LL ans = 0;
    for(int i = 1; i < n; i++){
        ans += a[i]-a[i-1]-1;
    }
    cout << ans << endl;
    return 0;
}
