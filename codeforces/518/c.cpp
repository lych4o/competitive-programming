#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("I64d",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1e6+10;

int n, m;
vector<int> to[maxn];
vector<pii> ans;
int main(){
	sc(n); sc(m);
	for(int i=0;i<m;i++){
		int u, v; sc(u); sc(v);
		to[u].pb(v); to[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		ans.clear();
		ans.pb(mk(i+n*i,i+n*i));
		for(int v: to[i]) {
			if(v>i) ans.pb(mk(v+n*i,i+n*v)), ans.pb(mk(v+n*i,i+n*i));
			else ans.pb(mk(i+n*i,v+n*i));
		}
		printf("%d\n",SZ(ans));
		for(pii u: ans) printf("%d %d\n",u.F-n,u.S-n);
	}
	return 0;
}
