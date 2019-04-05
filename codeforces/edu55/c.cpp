#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sz(x) ((int)x.size())
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
vector<int> sum[maxn];
int n, m, ans[maxn];
int cmp(int x, int y){return x>y;}
int solve(int x){
	if(x==0) return 0;
	//printf("solve(%d)\n",x);
	int ret = 0;
	for(int i=1;i<=m;i++){
		if(sz(sum[i])<x) continue;
		if(sum[i][x-1]>=0) ret += sum[i][x-1];
		//printf("%d\n",sum[i][x-1]);
	}
	return ret;
}
int main(){
	sc(n); sc(m);
	for(int i=0;i<n;i++){
		int u,v;sc(u); sc(v);
		sum[u].pb(v);
	}
	for(int i=1;i<=m;i++){
		sort(sum[i].begin(),sum[i].end(),cmp);
		for(int j=0;j<sz(sum[i]);j++){
			if(j>0) sum[i][j]+=sum[i][j-1];
			if(sum[i][j]>=0) ans[j]+=sum[i][j];
		}
	}
	int res=0;
	for(int i=0;i<n;i++){
		res=max(res,ans[i]);	
	}
	cout << res << endl;
	return 0;
}
