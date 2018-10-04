#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const LL mod = 998244353;
const int maxn = 1e5+10;
int n;
LL a[maxn];

int main(){
    sc(n);
    LL ans = 0, tmp = 1;
    for(int i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        ans += (a[i]*a[i]-a[i])/2+a[i];
        //printf("ans:%lld\n",ans);
        ans %= mod;
        tmp = tmp*(a[i]+1)%mod;
    }   
    cout << (ans+tmp+mod)%mod << endl;
    return 0;
}
