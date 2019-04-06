#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxv = 301;
const int mod = 1e9+7;
LL nop[maxv], p[62], bit[maxv];
void print(int x){for(int i=0;i<10;i++) printf("%d",(x>>i)&1);}
void seve(){
    int cnt = 0;
    memset(bit,0,sizeof(bit));
    for(int i=2;i<maxv;i++) if(!nop[i]){
        bit[i] |= (1LL<<cnt); p[cnt] = i;
        for(int j=2*i;j<maxv;j+=i) nop[j]=1, bit[j] |= (1LL<<cnt);
        cnt++;
    }
}
inline LL qpow(LL x, LL k){
    LL ret = 1;
    while(k){
        if(k&1) ret = ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
LL inv(LL x) { return qpow(x, mod-2);}
const int maxn = 4e5+10;
namespace sgt{
#define ls ((rt<<1)|1)
#define rs ((rt<<1)+2)
#define mid ((L+R)>>1)
    LL has[maxn*4], val[maxn*4], lzh[maxn*4], lzv[maxn*4];
    void build(int L, int R, int rt, int* a){
        lzh[rt] = 0; lzv[rt] = 1;
        if(L==R-1){ 
            has[rt] = bit[a[L]];
            val[rt] = a[L]; 
            return;
        }
        build(L,mid,ls,a); build(mid,R,rs,a);
        has[rt] = has[ls]|has[rs];
        val[rt] = val[ls]*val[rs]%mod;
    }
    void init(int N, int* a){ build(0,N,0,a);}
    inline void pd(int rt, int L, int R){
        has[ls]|=lzh[rt]; has[rs]|=lzh[rt]; lzh[rs]|=lzh[rt]; lzh[ls]|=lzh[rt]; lzh[rt] = 0;
        val[ls] = val[ls]*qpow(lzv[rt], mid-L)%mod; lzv[ls]=lzv[ls]*lzv[rt]%mod;
        val[rs] = val[rs]*qpow(lzv[rt], R-mid)%mod; lzv[rs]=lzv[rs]*lzv[rt]%mod;
        lzv[rt] = 1;
    }
    inline void pu(int rt, int L, int R){
        has[rt]=has[ls]|has[rs];
        val[rt]=val[rs]*val[ls]%mod;
    }
    void mul(int x, int y, int z, int rt, int L, int R){
        if(L>=y || R<=x) return;
        if(L>=x && R<=y){
            has[rt] |= bit[z]; lzh[rt] |= bit[z];
            val[rt] = val[rt]*qpow(z,R-L)%mod;
            lzv[rt] = lzv[rt]*z%mod;
            return;
        }
        pd(rt,L,R);
        mul(x,y,z,ls,L,mid);
        mul(x,y,z,rs,mid,R);
        pu(rt,L,R);
    }
#define mk make_pair
#define F first
#define S second
    pair<LL,LL> query(int x, int y, int rt, int L, int R){
        if(L>=y || R<=x) return mk(0,1);
        if(L>=x && R<=y) return mk(has[rt],val[rt]);
        pd(rt,L,R);
        pair<LL,LL> pl = query(x,y,ls,L,mid), pr = query(x,y,rs,mid,R);
        pu(rt,L,R);
        return mk(pl.F|pr.F, pl.S*pr.S%mod);
    }
}
int n, q, a[maxn], iv[maxv];
int main(){
    seve();
    sc(n); sc(q);
    for(int i=0;i<n;i++) sc(a[i]);
    for(int i=1;i<maxv;i++) iv[i] = inv(i);
    sgt::init(n,a);
    while(q--){
        char s[20]; int x, y, z;
        scanf("%s%d%d",s,&x,&y);
        x--; y;
        if(s[0]=='T'){
            pair<LL,LL> pll = sgt::query(x,y,0,0,n);
            LL ans = pll.S, vis = pll.F;
            for(int i=0;i<62;i++) if(vis&(1LL<<i))
                    ans = ans*iv[p[i]]%mod*(p[i]-1)%mod;
            printf("%lld\n", ans);
        }else{
            sc(z);
            sgt::mul(x,y,z,0,0,n);
        }
    }
    return 0;
}
