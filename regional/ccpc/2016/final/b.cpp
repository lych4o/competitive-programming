#include<bits/stdc++.h>
#define pLL pair<LL,LL>
#define SZ(x) ((int)x.size())
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define sll(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
int L, n, m;
LL w[maxn], d[maxn];
vector<LL> vp;
int main(){
	int T; sc(T);
	for(int kase=1;kase<=T;kase++){
		sc(L); sc(n); sc(m);
		priority_queue<pLL,vector<pLL>,greater<pLL> > q;
		for(int i=0;i<n;i++) sll(w[i]);
		for(int i=0;i<m;i++) sll(d[i]);
		for(int i=0;i<n;i++) q.push(mk(w[i],w[i]));
		vp.clear();
		for(int i=0;i<L;i++){
			pLL now = q.top(); q.pop();
			vp.pb(now.F); q.push(mk(now.F+now.S,now.S));
		}

		while(q.size()) q.pop();
		
		LL ans=0;
		for(int i=0;i<m;i++) q.push(mk(d[i],d[i]));
		for(int i=SZ(vp)-1;i>=0;i--){
			pLL now = q.top(); q.pop();
			ans = max(ans, now.F+vp[i]);
			q.push(mk(now.F+now.S, now.S));
		}
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}
