#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int maxv = 1e7+10;
int smp[maxv];
bool vis[maxv];
vector<int> p;
void seve(){
	for(int i=2;i<maxn;i++){
		if(!vis[i]){
			p.pb(i);
			smp[i]=i;
		}
		for(int j=0; j<SZ(p)&&i*p[j]<maxn; j++){
			vis[i*p[j]]=1;
			smp[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
const int maxn = 2e5+10;
vector<int> to[maxn], ps[maxn];
int bit[maxn], pt[maxn], tot, dep[maxn];
void add(int x, int v){for(int i=x;i<maxn;i+=i&-i) bit[i]+=v;}
int sum(int x){int s=0;for(int i=x;i>0;i-=i&-i)s+=bit[i]; return s;}
void dfs(int u, int f){
	ps[u].pb(tot);
	dep[u] = dep[f]+1;
    for(int v:to[u])if(v!=f){
        pt[++tot]=v;
        dfs(v, u);
    }
    pt[++tot]=u;
    ps[u].pb(tot);
}
int mn[maxn][20], hp[maxn]
void pre(){
	tot=0; dfs(1,1);
	for(int i=1, t=0;i<=tot;i++){
		mn[i][0]=pt[i];
		while((1<<(t+1))<i) t++;
		hp[i]=t;
	}
	for(int t=1;(1<<t)<=maxn;t++){
		for(int l=1,r=l+(1<<(t-1));r<=tot;l++,r++){
			mn[l][t]= (dep[mn[l][t-1]<dep[mn][r][t-1])?
					mn[l][t-1]:mn[r][t-1];
		}
	}
}
inline int rmq(int l, int r){
	if(l<r) swap(l,r);
    int t=hp[r-l+1];
    int u=mn[l][t], v=mn[r-(1<<t)+1][t];
    return dep[u]<dep[v]?u:v;
}
inline int psum(int u, int v){
	int lca=rmq(ps[u][0],ps[v][0]);
	return sum(ps[u][0])+sum(ps[v][0])-sum(ps[lca][0])-sum(ps[lca][0]-1);
}
int n, a[maxn], m;
struct query{
	int u,v,x,ans;
	pnt(int u=0,int v=0,int x=0,int ans=0):u(u),v(v),x(x),ans(ans){}
} q[maxn];
vector<pii> h[maxv], qh[maxv];

void debug(){
	int op,u,v;
	while(cin >> op >> u >> v){
		if(op==1)
	}
}
int main(){
	seve();
	sc(n);
	for(int i=1;i<n;i++){
		int u, v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		sc(a[i]);
		for(int tmp=a[i];tmp>1;){
			int cnt=0, pp=smp[tmp];
			while(tmp%pp==0) cnt++, tmp/=pp;
			h[pp].pb(mk(cnt,i));
		}
	}
	sc(m);
	for(int i=0;i<m;i++){
		sc(q[i].u); sc(q[i].v); sc(q[i].x);
		q[i].ans = 1;
		for(int tmp=a[i];tmp>1;){
			int cnt=0, pp=smp[tmp];
			while(tmp%pp==0) cnt++, tmp/=pp;
			qh[pp].pb(mk(cnt,i));
		}
	}
	for(int i=0;i<maxv;i++){
		if(SZ(qh)) solve(i);
	}
	return 0;
}
