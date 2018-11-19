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
int n, a[maxn], mx, sum;
int main(){
	sc(n);
	for(int i=0;i<n;i++){
		sc(a[i]);
		sum += a[i];
		mx = max(a[i],mx);
	}
	for(int i=mx;i;i++){
		int x=i*n-sum;
		if(x>sum) return printf("%d",i), 0;
	}
	return 0;
}//
