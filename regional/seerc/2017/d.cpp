#include<bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e5+10;
int f[maxn], n, m;
int Find(int x){
	if(x==f[x]) return x;
	return f[x]=Find(f[x]);
}
vector<int> v[maxn];
int main(){
	sc(m); sc(n);
	for(int i=1;i<=m;i++){
		f[i]=i;
		int k; sc(k);
		for(int j=0;j<k;j++){
			int tmp; sc(tmp);
			v[tmp].pb(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=v[i][0],y=v[i][1],
			fx=Find(x),fy=Find(y);
		if(fx!=fy) ans++, f[fx]=fy;
	}
	printf("%d\n",ans);
	return 0;
}
