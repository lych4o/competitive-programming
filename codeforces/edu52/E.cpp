#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#ifdef LYCH
    #define sll(x) scanf("%lld", &x)
#else
    #define sll(x) scanf("%I64d",&x)
#endif
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
const LL mod = 998244353;
const int maxn = 1e6+10;

LL n, m, a, b[maxn];

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k>0){
        if(k&1) ret=ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
int main(){
    cin >> n >> m >> a;
    LL ans = 1, iv2=qpow(2,mod-2);
    for(int i = 1; i <= m; i++){
        sll(b[i]);
        ans = ans*(qpow(a,2*(b[i]-b[i-1]))+qpow(a,b[i]-b[i-1]))%mod*iv2%mod;
    }
    ans = ans*qpow(a,n-b[m]-b[m])%mod;
    cout << ans << endl;
    return 0;
}
