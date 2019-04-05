#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const LL mod = 1e9+7, pp = 317;
const int maxn = 1e6+10;

LL a[maxn], k[maxn], n, sum[pp], sk[maxn];
set<int> st;

int main(){
	sc(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=1;i<n;i++) cin >> k[i];
	for(int i=0;i<n;i++){
		if(i>0) k[i] += k[i-1];
		sum[i/pp] += a[i];
		st.insert(i);
	}st.insert(n);
	for(int i=1;i<n;i++) sk[i] = sk[i-1]+k[i];
	int q; sc(q);
	while(q--){
		char op[20]; scanf("%s", op);
		int x, y; sc(x); sc(y); 
		if(op[0] == 's'){
			x--; y--;
			LL ans = 0;
			auto it = --st.upper_bound(x);
			int pre = *it; int nxt = *(++it);
			for(int i=x; i < x/pp*pp+pp && i <= y; i++){
				if(i == nxt){
					pre = nxt;
					nxt = *(++it);
				}
				ans += a[pre]+k[i]-k[pre];
				//printf("1 i:%d, pre:%d, %lld+%lld=%lld, nxt:%d, ans:%lld\n",
				//		i,pre,a[pre],k[i]-k[pre],a[pre]+k[i]-k[pre],nxt,ans);
			}
			for(int i=x/pp+1; i*pp+(pp-1) < y; i++){
				ans += sum[i];
				//printf("sum[%lld-%lld]:%lld\n", i*pp+1,i*pp+pp, sum[i]);
			}
			it = --st.upper_bound(y/pp*pp);
			pre = *it; nxt = *(++it);
			if(x/pp < y/pp) for(int i=y/pp*pp; i<=y; i++){
				if(i == nxt){
					pre = nxt;
					nxt = *(++it);
				}
				ans += a[pre]+k[i]-k[pre];
				//printf("2 i:%d, pre:%d, %lld+%lld=%lld, nxt:%d, ans:%lld\n",
				//		i,pre,a[pre],k[i]-k[pre],a[pre]+k[i]-k[pre],nxt,ans);
			}
			printf("%I64d\n", ans);
		}else{
			x--;
			auto it = --st.upper_bound(x);
			int pre = *it; int nxt = *(++it);
			a[x] = a[pre]+k[x]-k[pre]+y;
			pre = x;
			while(1){
				int l = pre/pp, r = (nxt-1)/pp,
					pl = l*pp+pp-1, pr = r*pp;
				sum[l] += y*1LL*(pl-pre+1);
				sum[r] += y*1LL*(nxt-pr);
				//printf("pre:%d, nxt:%d, l:%d, r:%d, y:%d\n",pre,nxt,l,r,y);
				for(int i = l+1; i < r; i++) sum[i] += y*pp;
				if(l==r) sum[l] -= y*pp;
				y = (a[x]+k[nxt]-k[x])-a[nxt];
				pre = nxt; 
				auto pit = it++;
				if(it==st.end() || y < 0) break;
				nxt = *it;
				st.erase(pit);
			}
			st.insert(x);
		}
		/*
		printf("st: ");
		for(int x: st) printf("%d ", x);
		puts("");
		auto it = st.begin();
		int pre = *it, nxt = *(++it);
		printf("a:");
		for(int i=0;i<n;i++){
			if(i==nxt){
				pre = nxt;
				nxt = *(++it);
			}
			printf("%lld ", a[pre]+k[i]-k[pre]);
		}puts("");*/
	}
	return 0;
}
