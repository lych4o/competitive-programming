#include<iostream>
#include<cstring>
#include<cstring>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;

const LL mod = 1e9+7;
const int maxn = 25, maxk = 1e4+10;
int n, q, v[maxn], c[maxn];
LL dp[maxk];

int main(){
    int T; sc(T);
    while(T--){
        sc(n); sc(q);
        for(int i = 1; i <= n; i++){
            sc(v[i]); sc(c[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i++) for(int j = 0; j < c[i]; j++){
            int val = v[i]<<j;
            for(int k = maxk-1; k-val >= 0; k--){
                dp[k] = (dp[k-val]+dp[k])%mod;
            }
        }
        while(q--){
            int s; sc(s);
            printf("%lld\n", dp[s]);
        }
    }   
    return 0;
}
