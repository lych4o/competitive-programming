#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const int maxn = 105;
const int mod = 1e9+7;

struct mat{
    int m[maxn][maxn];
    void init(){memset(m,0,sizeof(m));}
    mat(){init();}
    void unit(){ for(int i=1;i<maxn;i++) m[i][i]=1;}
    mat operator * (const mat& r) const{
        mat ret;
        for(int i=1;i<maxn;i++) for(int j=1;j<maxn;j++) for(int k=1;k<maxn;k++){
                ret.m[i][j] = (ret.m[i][j] + 1LL*m[i][k]*r.m[k][j]%mod)%mod;
        }
        return ret;
    }
    mat pow(LL k){
        mat x, ret; 
        x = *this; ret.unit();
        while(k>0){
            if(k&1) ret=ret*x;
            x = x*x;
            k >>= 1;
        }
        return ret;
    }
};
int main(){
    LL n, m;
    cin >> n >> m;
    mat x;
    if(n<m) return cout << 1 << endl, 0;
    x.m[1][1] = 1; x.m[1][m] = 1;
    for(int i=2;i<=m;i++) x.m[i][i-1] = 1;
    x = x.pow(n-m+1);
    LL ans = 0;
    for(int i=1;i<=m;i++) ans = (ans+x.m[1][i])%mod;
    cout << ans << endl;
    return 0;
}
