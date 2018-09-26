#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define sc(x) scanf("%d", &x)
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxk = 1e3+10;

int bit[maxk][maxk];
inline void add(int p, int x, int v){
    for(int i = x; i < maxk; i += i&-i)
        bit[p][i]+=v;
}
inline int query(int p, int x){
    int ret = 0;
    for(int i = x; i > 0; i -= i&-i)
        ret += bit[p][i];
    //printf("query(%d, %d):%d\n",p,x,ret);
    return ret;
}

const int maxn = 1e5+10;
int n, m, a[maxn], b[maxn], cnt[maxk];
LL sum;
void init(){
    sum = 0;
    memset(bit,0,sizeof(bit));
    memset(cnt,0,sizeof(cnt));
}

LL cal(LL x){
    LL ret = -sum;
    for(int i = 1; i < maxk; i++){
        if(cnt[i]==0) continue;
        ret += x/i*cnt[i];
        ret -= cnt[i]-query(i,x%i+1);
    }
    //printf("cal(%lld):%lld\n",x,ret);
    return ret;
}
int main(){
    int T; sc(T);
    while(T--){
        sc(n); sc(m); init();
        //printf("n:%d,m:%d\n",n,m);
        for(int i = 0; i < n; i++) sc(a[i]);
        for(int i = 0; i < n; i++){
            sc(b[i]);
            //printf("b[%d]:%d\n",i,b[i]);
            add(a[i], b[i]%a[i]+1, 1);
            sum += b[i]/a[i];
            cnt[a[i]]++;
        }       
        //printf("sum:%lld\n",sum);
        while(m--){
            int op, x, y; sc(op);
            if(op == 3){
                sc(x);
                LL L = 0, R = 2*(1000LL*x/n+1e9);
                while(L+1<R){
                    LL mid = (L+R)>>1;
                    if(cal(mid) >= x) R = mid;
                    else L = mid;
                }
                printf("%lld\n", R);
            }else{
                sc(x); sc(y); x--; 
                //printf("a[%d]:%d,b[%d]:%d\n",x,a[x],x,b[x]);
                add(a[x],b[x]%a[x]+1,-1); sum -= b[x]/a[x];
                if(op==1){
                    cnt[a[x]]--;
                    a[x] = y;
                    cnt[a[x]]++;
                }
                else b[x] = y;
                add(a[x],b[x]%a[x]+1,1); sum += b[x]/a[x];
                //printf("a[%d]:%d,b[%d]:%d\n",x,a[x],x,b[x]);
                //printf("sum:%lld\n",sum);
            }
        }
    }
    return 0;
}
