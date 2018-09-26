#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const LL mod = 998244353;

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k > 0){
        if(k&1) ret = ret*x%mod;
        k >>= 1;
        x = x*x%mod;
    }
    return ret;
}

int main(){
    int T; sc(T);
    while(T--){
        int m; sc(m);
        LL ans = 1;
        for(int i = 0; i < m; i++){
            int p, q; sc(p); sc(q);
            LL tmp = qpow(p,q) + qpow(p,q-1)*q%mod*(p-1)%mod;
            ans = ans*tmp%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
