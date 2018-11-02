#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define ln puts("")
#define sp putchar(' ')
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fout fflush(stdout)
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
//const LL mod = 1e9+7;
//const int maxn = 1e6+10;

LL n, m;
int main(){
    cin >> n >> m;
    LL ans1 = 0, tmp = n, ans2=0;
    for(int i = 1; i <= m; i++){
        tmp -= 2;
        if(tmp < 0){
            tmp = 0;
            break;
        }
    }
    ans1 = tmp;
    tmp = n;
    LL res = 0;
    for(LL i = 1; i <= n; i++){
        LL x = i*(i-1)/2;
        if(x>=m){
            res = i;
            break;
        }
    }
    m -= res*(res-1)/2;
    if(res==1) ans2=n;
    else ans2 = n-res;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
