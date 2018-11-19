#include<bits/stdc++.h>
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
vector<int> vq, vx;
int idq(int q){return lower_bound(ALL(vq),q)-vq.begin();}
int idx(int x){return lower_bound(ALL(vx),x)-vx.begin();}
struct hh{
	int x,r,q;
	hh(int x=0,int r=0,int q=0):x(x),r(r),q(q){}
	bool operator < (const hh& rhs) const{
		return r>rhs.r;
	}
} a[maxn];
int n, k;
/****seg tree:[l,r)***/
#define mid (((l)+(r))>>1)
int root[maxn],ls[maxn*30],rs[maxn*30],sum[maxn*30],tot;
void add(int &rt, int p, int v, int l=0, int r=maxn){
	//printf("add(%d,[%d,%d),[%d,%d))\n",rt,p,v,l,r);
	if(l>p || r<=p) return;
	if(!rt) rt = ++tot;
	sum[rt] += v;
	if(l==r-1) return;
    add(ls[rt],p,v,l,mid); add(rs[rt],p,v,mid,r);
}
int query(int rt, int x, int y, int l=0, int r=maxn){
	//printf("q(%d,[%d,%d),[%d,%d))\n",rt,x,y,l,r);
    if(!rt||l>=y||r<=x) return 0;
	if(l>=x&&r<=y) return sum[rt];
	int a=query(ls[rt],x,y,l,mid),b=query(rs[rt],x,y,mid,r);
	return a+b;
}
int main(){
	sc(n); sc(k);
	for(int i=0;i<n;i++){
		sc(a[i].x); sc(a[i].r); sc(a[i].q);
		vx.pb(a[i].x); vq.pb(a[i].q);
	}
	sort(ALL(vx)); vx.erase(unique(ALL(vx)),vx.end());
	sort(ALL(vq)); vq.erase(unique(ALL(vq)),vq.end());
	sort(a,a+n);
	LL ans = 0;
    for(int i=0;i<n;i++){
		//printf("i:%d\n",i);
        int x=idx(a[i].x),L=idx(a[i].x-a[i].r),
        //R=idx(a[i].x+a[i].r)+1;
		R=upper_bound(ALL(vx),a[i].x+a[i].r)-vx.begin();
        for(int qq=a[i].q-k;qq<=a[i].q+k;qq++){
			int q=idq(qq); if(vq[q]!=qq) continue;
            ans += query(root[q],L,R);
        }
        add(root[idq(a[i].q)],x,1);
    }
    printf("%lld\n", ans);
	return 0;
}
