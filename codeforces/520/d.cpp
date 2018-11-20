#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef long long LL;
//const int maxn = 1e6+10;
LL n;
int main(){
    sll(n);
    LL ans=0;
    for(int i=2;i<=n;i++){
        LL nm = n/i;
        LL cnt = (2+nm)*2*(nm-1);
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}
