#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
int n, f[maxn], d[maxn], p[maxn], h[maxn];
vector<int> to[maxn], v, dv;
void dfs(int u){
    d[u]=d[f[u]]+1;
    //printf("d[%d]:%d\n",u,d[u]);
    p[u]=SZ(v);
    v.pb(d[u]);
    dv.pb(u);
    for(int vv: to[u]){
        dfs(vv);
        v.pb(d[u]);
        dv.pb(u);
    }
}
pii L[maxn][20],R[maxn][20];
int mn[maxn][20];
void init(){
    /*for(int i=0;i<SZ(v);i++){
        //printf("v[%d]:(%d,%d)\n",i,dv[i],v[i]);
        //printf("%d ",v[i]);
        printf("%d ",dv[i]);
    }puts("");
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    puts("");*/

    for(int i=1,k=0;i<maxn;i++){
        while((1<<(k+1))<=i) k++;
        h[i]=k;
        //printf("h[%d]:%d\n",i,h[i]);
    }
    
    for(int i=1;i<=n;i++) L[i][0]=R[i][0]=mk(p[i],i);
    for(int w=1,len=2;len<=n;w++,len<<=1){
        for(int l=1;l+len-1<=n;l++){
            L[l][w]=min(L[l][w-1],L[l+len/2][w-1]);
            R[l][w]=max(R[l][w-1],R[l+len/2][w-1]);
        }
    }
    for(int i=0;i<SZ(v);i++) mn[i][0]=v[i];
    //printf("%d\n",SZ(v));
    for(int w=1,len=2;len<=SZ(v);w++,len<<=1){
        for(int l=0;l+len-1<SZ(v);l++){
            mn[l][w]=min(mn[l][w-1],mn[l+len/2][w-1]); 
            //printf("mn[%d][%d]:%d\n",l,w,mn[l][w]); 
        }
    }
}
inline pii qL(int l, int r){
    if(l>r) return mk(maxn+1,maxn+1);
    int w=h[r-l+1], len=(1<<w);
    //printf("qL(%d,%d):(%d,%d)\n",l,r,L[l][w].F,L[r-len+1][w].F);
    return min(L[l][w],L[r-len+1][w]);
}
inline pii qR(int l, int r){
    if(l>r) return mk(0,0);
    int w=h[r-l+1], len=(1<<w);
    //printf("qR(%d,%d):(%d,%d)\n",l,r,R[l][w].F,R[r-len+1][w].F);
    return max(R[l][w],R[r-len+1][w]);
}
inline int qD(int l, int r){
    int w=h[r-l+1], len=(1<<w);
    //printf("qD(%d,%d):(%d,%d)\n",
      //      l,r,mn[l][w],mn[r-len+1][w]);
    return min(mn[l][w],mn[r-len+1][w]);
}
int q;
int main(){
    sc(n); sc(q);
    for(int i=2;i<=n;i++){
        sc(f[i]);
        to[f[i]].pb(i);
    }
    dfs(1);
    init();
    while(q--){
        int l,r; sc(l); sc(r);
        int p1=qL(l,r).S;
        int lp = min(qL(l,p1-1).F,qL(p1+1,r).F),
            rp = max(qR(l,p1-1).F,qR(p1+1,r).F);
        //printf("lp:(%d,%d), rp:%d\n",
          //      qL(l,p1-1).F,qL(p1+1,r).F,rp);
        int ans1=qD(lp,rp);
        int p2 = qR(l,r).S;
        //printf("p1:%d, p2:%d\n",p1,p2);
        lp=min(qL(l,p2-1).F,qL(p2+1,r).F);
        rp=max(qR(l,p2-1).F,qR(p2+1,r).F);
        int ans2=qD(lp,rp);
        if(ans1<ans2){
            printf("%d %d\n",p2,ans2-1);
        }else printf("%d %d\n",p1,ans1-1);
    }
    return 0;
}
