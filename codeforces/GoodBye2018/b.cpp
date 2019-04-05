#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
typedef double db;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

map<pii, int> mp;
pii p[maxn], a[maxn];
int n, vis[maxn], as[maxn];
pii add(pii x, pii y){
	return mk(x.F+y.F,x.S+y.S);
}
pii sub(pii x, pii y){
	return mk(x.F-y.F,x.S-y.S);
}
int check(int x){
	memset(vis,0,sizeof(vis));
	vis[x]=1; as[0] = x;
	pii ans = add(p[0],a[x]);
	for(int i=1;i<n;i++){
		pii nd = sub(ans, p[i]);
		if(mp.find(nd)==mp.end()) return 0;
		int id = mp[nd];
		if(vis[id]) return 0;
		vis[id] = 1;
		as[i] = id;
	}
	return 1;
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		sc(p[i].F); sc(p[i].S);
	}
	for(int i=0;i<n;i++){
		sc(a[i].F); sc(a[i].S);
		mp[a[i]] = i;
	}
	for(int i=0;i<n;i++){
		if(check(i)){
			printf("%d %d\n", add(p[0],a[i]).F,add(p[0],a[i]).S);
			return 0;
		}
	}
	return 0;
}
