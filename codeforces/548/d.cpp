#include<bits/stdc++.h>
#define debug puts("???")
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const LL mod = 1e9+7;
const int maxn = 1e5+10;

LL gcd(LL a, LL b){
    if(!a) return b;
    return gcd(b%a, a);
}

vector<int> p;
int nop[maxn], mx[maxn], pw[maxn];
void init(){
    for(int i=2;i<maxn;i++){
        if(!nop[i]) p.pb(i), has[i].pb(i), mx[i] = i;
        for(int j=0;i*p[j]<maxn && j<p.size(); j++){
            nop[i*p[j]] = 1;
            mx[i*p[j]] = mx[i];
            if(i%p[j]==0){
                break;
            }
        }
    }
    for(int i=2;i<maxn;i++){
        int xxx = i;
        while(mx[xxx] == mx[i]) xxx /= mx[i], pw[i]++;
    }
}
LL qpow(LL x, LL k){
    //printf("qpow(%lld,%lld):\n",x,k);
    LL ret = 1;
    while(k>0){
        //printf("k:%lld\n",k);
        if(k&1) ret=ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
int m;
vector<int> vi;
LL iv[maxn];
LL dp[maxn], ;

void dfs(int x, LL pre){
    //printf("dfs(%d, %lld)\n",x,pre);
    LL ret = 0;
    for(int pp: has[x]){
        LL y = x/pp, k = m/y - pre;
        printf("f(%lld):%lld\n", y, k);
        tmp += (dp[y]+1)*k%mod*iv[m]%mod;
        dfs(y, pre+k);
    }
}
int main(){
    init();
    sc(m);
    for(int i=1;i<=m;i++){
        iv[i] = qpow(i, mod-2);
        //printf("iv[%d]:%lld\n",i,iv[i]);
    }
    dp[1] = 1;
    LL ans = dp[1];
    for(int i=2;i<=m;i++){
        printf("i:%d\n",i);
        int x = i;
        dp[i] = tmp = 0;
        dfs(i, m/i);
        dp[i] = tmp%mod;
        LL fuck = m*iv[m-m/i]%mod, shit = m/i*iv[m]%mod;
        dp[i] = (dp[i]+shit)*fuck%mod;
        ans = (ans+dp[i])%mod;
        //printf("dp[%d]:%lld\n", i, dp[i]);
    }
    //printf("ans:%lld\n", ans);
    ans = ans*iv[m]%mod;
    cout << ans << endl;
    return 0;
}
