#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 3e5+10;
int n;
LL a[maxn], w[maxn],wsum[maxn],ans[maxn],res;
int main(){
    sc(n); wsum[0]=0;
    for(int i = 1; i <= n; i++) sll(a[i]);
    for(int i = 1; i <= n; i++) 
        sll(w[i]),wsum[i]=(wsum[i-1]+w[i])%mod;
    
    ans[1] = wsum[n];
    res = 0;
    for(int i = 2; i <= (n+1)/2; i++){
        ans[i]=(ans[i-1]+wsum[n-i+1]-wsum[i-1]);
    }
    for(int i = 1; i<= (n+1)/2; i++){
        if((i==(n+1)/2)&&(n&1)) res += ans[i]*a[i]%mod; 
        else res += ans[i]*(a[i]+a[n-i+1])%mod;
    }
    res %= mod;
    cout << (res+mod)%mod << endl;
    return 0;
}
