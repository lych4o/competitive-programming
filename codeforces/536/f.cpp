#include<bits/stdc++.h>
#define debug puts("???")
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const LL mod = 998244353;
const int maxn = 105;
LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b) return x=1,y=0,a;
    LL g = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return g;
}
LL qpow(LL x, LL k){
    LL ret = 1;
    while(k){
        if(k&1) ret = ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
namespace BSGS{
    map<LL, LL> mp;
    LL bsgs(LL a, LL b){
        mp.clear();
        LL u = (LL)sqrt(mod) + 1, now = 1, stp;
        for(LL i = 0; i < u; i++){
            LL tmp = b*qpow(now, mod-2)%mod;
            mp[tmp] = i;
            now = now*a%mod;
        }
        stp = now;
        now = 1;
        for(LL i = 0; i < mod; i += u){
            if(mp.count(now)) return i+mp[now];
            now = now*stp%mod;
        }
        return -1;
    }
}
int n, v, m, b[maxn], a[maxn], c[maxn], d[maxn];
struct Mat{
    LL m[maxn][maxn];
    Mat(){memset(m,0,sizeof(m));}
    void unit(){
        memset(m,0,sizeof(m));
        for(int i=1;i<=n;i++) m[i][i]=1;
    }
    Mat operator * (const Mat& x) const{
        Mat ret;
        for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            ret.m[i][j] += m[i][k]*x.m[k][j];
            ret.m[i][j] %= (mod-1);
        }
        return ret;
    }
    void print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%lld ", m[i][j]);
            }puts("");
        }puts("");
    }
    Mat pw(LL k){
        Mat ret, x = *this;
        ret.unit();
        while(k){
            if(k&1){
                ret = ret*x;
            }
            x = x*x;
            k >>= 1;
        }
        return ret;
    }
};
LL solve(LL a, LL b, LL c){
    if(c == 0) return 0;
    LL x, y, g = exgcd(a,b,x,y);
    if(c % g) return -1;
    a /= g; b /= g; c /= g;
    x *= c; y *= c;
    if(x < 0) x += ((-x)/b+1)*b;
    return x%(mod-1);
}
void DEBUG(){
    int x;
    while(cin >> x){
        LL p = BSGS::bsgs(3,x);
        cout << p << " " << qpow(3,p) << endl;
    }
}
int main(){
    //DEBUG();
    sc(n);
    Mat mat;
    for(int i=1;i<=n;i++) sc(b[i]), mat.m[1][i]=b[i];
    for(int i=1;i<n;i++) mat.m[i+1][i] = 1;
    //mat.print();
    sc(m); sc(v);
    mat = mat.pw(m-n);
    //mat.print();
    LL pv = BSGS::bsgs(3, v);
    LL ans = solve(mat.m[1][1], mod-1, pv);
    if(ans >= 0) printf("%lld\n", qpow(3, ans));
    else printf("-1\n");
    return 0;
}
