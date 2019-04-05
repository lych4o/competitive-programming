#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define debug puts("???")
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
const LL mod = 1e9+7;
LL bit[maxn];
void add(int x, LL v){for(int i=x;i<maxn;i+=i&-i)bit[i]+=v;}
LL sum(int x){
	LL ret=0;
	for(int i=x;i>0;i-=i&-i) ret+=bit[i];
	return ret;
}

vector<int> v;
int n, m, w[maxn], a[maxn], id[maxn], ps[maxn];
LL wps[maxn];
int main(){
	sc(n); sc(m); v.pb(-1);
	for(int i=1;i<=n;i++) sc(a[i]), a[i]-=i, v.pb(a[i]);
	for(int i=1;i<=n;i++) sc(w[i]);
	sort(ALL(v)); v.erase(unique(ALL(v)),v.end());
	for(int i=1;i<=n;i++) id[i]=lower_bound(ALL(v),a[i])-v.begin();
	for(int i=1;i<=n;i++) add(id[i], w[i]), ps[id[i]]++, wps[id[i]]+=w[i]*a[i]%mod;
	for(int i=1;i<maxn;i++) ps[i]+=ps[i-1], wps[i]=(wps[i]+wps[i-1])%mod;
	while(m--){
		int x,y; sc(x); sc(y);
		if(x<0){
			x *= -1; add(id[x], -w[x]);
			add(id[x], y); w[x] = y;
		}else{
			LL all=sum(id[y])-sum(id[x]-1), sl=sum(id[x]-1);
			int L=id[x]-1, R=id[y];
            while(L+1<R){
				int mid=(L+R)>>1;
				if(2*(sum(mid)-sl)>=all) R=mid;
				else L=mid;
            }
            LL lc=ps[R-1]-ps[id[x]-1], rc=ps[id[y]]-ps[R];
            LL ans = lc*v[R]%mod-(wps[R-1]-wps[id[x]-1]) +
				     (wps[id[y]]-wps[R])-rc*v[R];
			printf("%lld\n", (ans%mod+mod)%mod);
		}
	}
	return 0;
}
