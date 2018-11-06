#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const LL INF = 2e18+10;
const int maxn = 1e5+10;
LL pw[maxn];
int n, a[maxn]; 
LL k;
//number of x in [l,r] that x%2 == op
inline LL cnt(int l, int r, int op){
    if(l>r) return 0;
    return (r-l+1)/2 + (((r-l+1)%2)&&(r%2==op));
}
inline LL cal_odd(int p){
    LL len=(n+1)/2;
    LL r1=cnt(p+1,(len+1)/2*2-1,1),r2=cnt(p+1,n,0);
    return pw[r1+r2];
}
inline LL cal_eve(int p){
    LL len=n/2;
    LL r1=cnt(p+1,(len+1)/2*2,0), r2=cnt(p+1,n,1);
    return pw[r1+r2];
}
inline LL cal_all(int p){
    LL len1=(n+1)/2,len2=n/2;
    LL r1=cnt(p+1,(len1+1)/2*2-1,1),r2=cnt(p+1,(len2+1)/2*2,0);
    return pw[r1+r2];
}
inline LL cal(int p, int op=3){
    if(op==3) return cal_odd(p)+cal_eve(p)-cal_all(p);
    else if(op==2) return cal_odd(p);
    else if(op==1) return cal_eve(p);
    else return 0;
}
void solve(){
    int i;
    for(i=1;i<=(n+1)/2;i++){//before middle
        if(cal(i,3) >= k) a[i]=0;
        else a[i]=1, k-=cal(i,3);
    }
    int f0=1,f1=1;
    for(;i<=n;i++){//after middle
        int j = (n%2)?n-i+1: (n/2-(i+1)/2+1)*2-i%2;
        int f[2]={f0,f1};
        a[i]=0;
        if(a[i]!=a[j]) f[i%2]=0;
        int op=f[0]+2*f[1];
        if(op==0){a[i]=1; continue;}
        if(cal(i,op) >= k) f0=f[0],f1=f[1],a[i]=0;
        else{
            k -= cal(i,op);
            a[i]=1; f[0]=f0; f[1]=f1;
            if(a[i]!=a[j]) f[i%2]=0;
            f0 = f[0], f1 = f[1];
        }
    }
}
int main(){
    pw[0]=1; for(int i=1;i<maxn;i++)pw[i]=min(INF,pw[i-1]*2);
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); sll(k); solve();
        printf("Case #%d: ",kase);
        if(k>1)  printf("NOT FOUND!");
        else for(int i=1;i<=n;i++) printf("%d",a[i]);
        puts("");
    }
    return 0;
}
