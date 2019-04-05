#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const int maxn = 1e4+10;
int n,a[maxn];
vector<pii> G, p;
int solve(){
	int c1=0, tot=0, p1, p2;
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			p.pb(mk(a[i]-2,i));
			tot += a[i]-2;
		}else{
			if(c1==0) p1=i;
			else if(c1==1) p2=i;
			c1++;
		}
	}
	if(c1==0){
		for(int i=1;i<n;i++) G.pb(mk(i,i+1));
		return n-1;
	}else if(c1==1){
		int pre=p1;
		for(int i=1;i<=n;i++){
			if(i==p1) continue;
			G.pb(mk(pre,i));
			pre=i;
		}
		return n-1;
	}else if(c1==2){
		int pre=p1;
		for(int i=1;i<=n;i++){
			if(i==p1||i==p2) continue;
			G.pb(mk(pre,i));
			pre=i;
		}
		G.pb(mk(pre,p2));
		return n-1;
	}else{
		if(tot<c1-2) return 0;
		int pre=p1,ret=1;
		for(int i=1;i<=n;i++) if(a[i]>1){
			ret++;
			G.pb(mk(pre,i));
			pre=i;
		}
		G.pb(mk(pre,p2));
		for(int i=1,j=0;i<=n;i++)if(a[i]==1&&i!=p1&&i!=p2){
			while(p[j].F==0) j++;
			G.pb(mk(i,p[j].S));
			p[j].F--;
		}
		return ret;
	}
}
int main(){
	sc(n); 
	for(int i=1;i<=n;i++) sc(a[i]);
	int ans=solve();
	if(ans){
		printf("YES %d\n%d\n",ans,(int)G.size());
		for(int i=0;i<(int)G.size();i++) printf("%d %d\n",G[i].F,G[i].S);
	}else puts("NO");
	return 0;
}
