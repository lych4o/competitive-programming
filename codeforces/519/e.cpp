#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 3e5+10;

vector<int> to[maxn];
int n, m, rk[maxn], x[maxn], y[maxn];
LL sx[maxn], sy[maxn], ans[maxn];
int cmp(int i, int j){return x[i]-y[i]<x[j]-y[j];}
inline LL sco(int i, int j){return min(x[i]+y[j],x[j]+y[i]);}
int main(){
	sc(n); sc(m);
	for(int i=1;i<=n;i++) sc(x[i]),sc(y[i]),rk[i]=i;
	for(int i=0;i<m;i++){
		int u,v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;i++){
		sx[i]=sx[i-1]+x[rk[i]];
		sy[i]=sy[i-1]+y[rk[i]];
		//printf("rk[%d]:%d, (%d,%d), sx:%lld, sy:%lld\n",
			//	i,rk[i],x[rk[i]],y[rk[i]],sx[i],sy[i]);
	}
	for(int i=1;i<=n;i++){
		int p=rk[i];
		ans[p] = 1LL*y[p]*(i-1)+sx[i-1]+1LL*x[p]*(n-i)+sy[n]-sy[i];
		for(int v: to[p])
			ans[p] -= sco(p,v);
	}
	for(int i=1;i<=n;i++) printf("%lld ", ans[i]); puts("");
	return 0;
}
