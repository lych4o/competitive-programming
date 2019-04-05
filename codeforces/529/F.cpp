#include<bits/stdc++.h>
#define sll(x) scanf("%I64d",&x)
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
int f[maxn];
int Find(int x){if(f[x]==x) return x; else return f[x]=Find(f[x]);}
struct hh{
	int u,v;
	LL w;
	hh(int u=0,int v=0,LL w=0):u(u),v(v),w(w){}
	bool operator < (const hh& rhs) const{
		return w > rhs.w;
	}
};
priority_queue<hh> pq;
int n, m;
LL a[maxn];
int main(){
	sc(n); sc(m);
	LL mn = 1e12+10;
	int p;
	for(int i=1;i<=n;i++){
		sll(a[i]), f[i]=i;
		if(a[i]<mn) mn=a[i],p=i;
	}
	for(int i=1;i<=n;i++) pq.push(hh(i,p,a[i]+a[p]));
	for(int i=0;i<m;i++){
		int u,v; LL w; sc(u); sc(v); sll(w);
		pq.push(hh(u,v,w));
	}
	LL ans=0, cnt=1;
	while(cnt<n){
		hh e = pq.top(); pq.pop();
		int u=e.u,v=e.v; LL w=e.w;
		//printf("cnt:%I64d, (%d,%d,%I64d)\n",cnt,u,v,w);
		if(Find(u)==Find(v)) continue;
		f[Find(u)]=f[Find(v)];
		ans += w;
		cnt++;
	}
	printf("%I64d\n", ans);
	return 0;
}
