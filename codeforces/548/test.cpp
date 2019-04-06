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
int nop[maxn], mx[maxn], cnt[maxn];
void init(){
    mx[1] = 1;
    for(int i=2;i<maxn;i++){
        if(!nop[i]) p.pb(i), cnt[i] = 1, mx[i] = i;
        for(int j=0;i*p[j]<maxn && j<p.size(); j++){
            mx[i*p[j]] = mx[i];
            cnt[i*p[j]] = cnt[i]+1;
            nop[i*p[j]] = 1;
            if(i%p[j]==0){
                break;
            }
        }
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
LL iv[maxn];
LL dp[maxn];
int main(){
    init();
	LL x, y;
	while(cin >> x >> y){
        cout << x*qpow(y, mod-2)%mod << endl;
    }
    return 0;
}
