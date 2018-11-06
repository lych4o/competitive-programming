#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
#define sll(x) scanf("%lld", &x)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;

LL G, P, v[maxn];
int n;

int check(LL x){
    LL now = x, mx = x, stp=P;
    for(int i=1;i<=n&&stp>0;i++,stp--){
        now += v[i];
        if(now<0) now=0;
        mx = max(mx, now);
    }
    if(now < x || !stp) return mx>=G;
    LL pre = now, flg=0;
    for(int i=1;i<=n&&stp>0;i++,stp--){
        now += v[i];
        if(now<0) now=0,flg=1;
        mx = max(mx, now);
    }
    if(!stp || flg) return mx>=G;
    LL d = now-pre;
    for(int i=1;i<=n&&stp>0;i++,stp--){
        now += v[i];
        if(now<0) now=0;
        mx = max(mx, now);
        LL rnd = (G-now+d-1)/d;
        if(rnd <= stp/n) return 1;
    }
    return mx>=G;
}

int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); sll(G); sll(P);
        for(int i=1; i<=n; i++) sll(v[i]);
        LL L=-1,R=G;
        while(L+1<R){
            LL mid=(L+R)>>1;
            //printf("L:%lld, R:%lld, mid:%lld\n",L,R,mid);
            if(check(mid)) R = mid;
            else L = mid;
        }
        printf("Case #%d: %lld\n",kase,R);
    }
    return 0;
}
