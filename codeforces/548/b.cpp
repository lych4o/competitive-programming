#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
typedef long long LL;
//typedef pair<int,int> pii;
//typedef pair<LL,LL> pLL;
using namespace std;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n;
LL a[maxn];
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    LL ans = 0, pre = 1e9+10;
    for(int i=n-1;i>=0;i--){
        LL v = min(a[i], pre-1);
        ans += min(a[i], pre-1);
        //printf("%lld\n", min(a[i], pre-1));
        pre = max(1LL, v);
    }
    cout << ans << endl;
    return 0;
}
