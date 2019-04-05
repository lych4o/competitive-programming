#include<bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int mod = 998244353;
const int maxn = 1e6+10;
int n, m, f[maxn];
vector<int> to[maxn];
inline int Find(int x){ return f[x]==x?x:(f[x]=Find(f[x]));}
int cnt[maxn],vis[maxn],pw[maxn];
int join(int x, int y){
	int fx=Find(x), fy=Find(y),
		fxx=Find(x+n), fyy=Find(y+n);
	if(fx==fy || fx==fxx || fy==fyy) return 0;
	f[fxx] = fy; f[fyy] = fx;
	return 1;
}
int main(){
	int T; sc(T);
	pw[0]=1;
	for(int i=1;i<maxn;i++) pw[i]=pw[i-1]*2%mod;
	while(T--){
		sc(n); sc(m);
		for(int i=1;i<=2*n;i++) to[i].clear(), f[i]=i, cnt[i]=vis[i]=0;
		int flg=1;
		for(int i=0;i<m;i++){
			int u, v; sc(u); sc(v);
			to[u].pb(v); to[v].pb(u);
			if(join(u,v)==0) flg=0;
		}
		if(!flg){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++) cnt[Find(i)]++;
		LL ans=1;
		for(int i=1;i<=n;i++) if(!vis[Find(i)]){
			int fi=Find(i), fii=Find(i+n);
			vis[fi]=vis[fii]=1;
			ans = ans*(pw[cnt[fi]]+pw[cnt[fii]])%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
