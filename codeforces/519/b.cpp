#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1e6+10;
int n, a[maxn];
vector<int> ans;
int check(int x){
	for(int i=x+1;i<=n;i++){
		int p=(i-1)%x + 1;
		if(a[i]!=a[p]) return 0;
	}
	return 1;
}
int main(){
	sc(n);
	for(int i=1;i<=n;i++){
		sc(a[i]);
	}
	for(int i=n;i>=1;i--) a[i] -= a[i-1];
	for(int i=1;i<=n;i++){
		if(check(i)) ans.pb(i);
	}
	printf("%d\n", SZ(ans));
	for(int i=0;i<SZ(ans);i++){
		printf("%d ", ans[i]);
	}puts("");
	return 0;
}
