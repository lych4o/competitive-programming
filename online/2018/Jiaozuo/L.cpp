#include<iostream>
#include<cstdio>
#include<cstring>
#define sc(x) scanf("%d", &x)
using namespace std;

typedef long long LL;
const LL mod = 1e9+7;
//const int maxn = 105;

struct mat{
    LL m[9][9];
    void init(){memset(m,0,sizeof(m));}
    void unit(){memset(m,0,sizeof(m)); for(int i=0;i<9;i++)m[i][i]=1;}
    mat(){memset(m,0,sizeof(m));}
};
mat mul(mat a, mat b){
    mat c;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]%mod);
            }
            c.m[i][j] %= mod;
        }
    }
    return c;
}
mat qpow(mat x, LL k){
    mat ret; ret.unit();
    while(k > 0){
        if(k&1) ret = mul(ret,x);
        x = mul(x,x);
        k >>= 1;
    }
    return ret;
}

int main(){
    int T; sc(T);
    while(T--){
        mat x;
        for(int p = 0; p < 3; p++) for(int q = 0; q < 3; q++) 
            for(int i = 0; i < 3; i++){
            int now = p*3+q, nxt = i*3+p;
            if(p==q && q==i) continue;
            if(i==q && i==2) continue;
            if(i!=p && p!=q && i!=q && p==2) continue;
            x.m[now][nxt]++;
        }
        LL n; scanf("%lld", &n);
        if(n <= 2){
            if(n==1) puts("3");
            else puts("9");
            continue;
        }
        x = qpow(x,n-2);
        LL ans = 0;
        for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++){
            ans = (ans + x.m[i][j])%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
