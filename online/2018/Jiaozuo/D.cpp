#include<iostream>
#include<cstdio>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxn = 300;
int n, m;
LL iv[maxn], ans[maxn][maxn];

LL qpow(LL x, LL k){
    LL res = 1;
    while(k > 0){
        if(k&1) res=res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}

inline LL c(LL x, LL y){
    if(y > x) return 0;
    if(y > x-y) y = x-y;
    LL ret = 1;
    for(int i = 1; i <= y; i++){
        ret = ret*iv[i]%mod*(x-i+1)%mod;
    }
    return ret;
}
///ways to get sum k with x numbers
inline LL g(int val, int x){
    /*LL ret = 1;
    for(int i = 1; i <= val; i++){
        ret = ret*iv[i]%mod*(val+x-i)%mod;
    }
    return ret;*/
    return c(val+x-1,x-1);
}

///ways to get sum k with x numbers, and max = v
LL f(int x, int k, int v){
    if(ans[x][k] >= 0) return ans[x][k];
    if(1LL*x*v < k) return ans[x][k] = 0;
    ans[x][k] = 0;
    int sum = k;
    for(int i = 0; i < x && sum >= 0; i++){
        int kk = (i&1)?-1:1;
        ans[x][k] += kk*g(sum,x);
        sum -= v+1;
    }
    return ans[x][k] = (ans[x][k]%mod+mod)%mod;
}

int main(){
    iv[1] = 1;
    for(int i = 2; i < maxn; i++) iv[i] = qpow(i,mod-2);
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(ans, -1, sizeof(ans));
        LL denom = g(m, n), numer = 0;
        for(int i = 1; i <= m; i++){
            printf("f(%d,%d,%d):%lld\n",n-1,m-i,i,f(n-1,m-i,i));
            numer += i*f(n-1,m-i,i)*n%mod;
        }
        printf("%lld\n", numer*qpow(denom,mod-2));
    }
    return 0;
}
