#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;

LL n;

int main(){
    cin >> n;
    LL ans = 0, tmp = n;
    while(tmp>=10){
        //printf("%lld-->",tmp);
        int x = tmp%10;
        tmp /= 10;
        if(x < 9){
            tmp--;
            ans += 10+x;
        }else ans += x;
        //printf("%lld, ans:%lld\n", tmp, ans);
    }
    cout << ans+tmp << endl;
    return 0;
}
