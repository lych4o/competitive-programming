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
LL n,m,k,l;
int main(){
	cin >> n >> m >> k >> l;
	LL all=k+l;	
	LL k = (all+m-1)/m;
	if(k > n/m) printf("-1\n");
	else printf("%lld\n",k);
	return 0;
}
