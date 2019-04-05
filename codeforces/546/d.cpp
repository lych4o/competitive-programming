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
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int a[maxn], n, m, vis[maxn];
vector<int> to[maxn];

int main(){
	sc(n); sc(m);
	for(int i=0;i<n;i++) sc(a[i]);
	for(int i=0;i<m;i++){
		int u, v; sc(u); sc(v);
		to[u].pb(v);
	}
	vis[a[n-1]] = 1;
	int ans = 0, cnt = 1;
	for(int i=n-2;i>=0;i--){
		int tmp = 0;
		for(int v: to[a[i]]){
			tmp += vis[v];
		}
		if(tmp >= cnt) ans++;
		else vis[a[i]]=1, cnt++;
	}
	printf("%d\n", ans);
	return 0;
}
