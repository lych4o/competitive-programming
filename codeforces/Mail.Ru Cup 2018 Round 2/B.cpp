#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 1e5+10;

LL n, m, l, a[maxn], ans;
int main(){
	sll(n); sll(m); sll(l); ans = 0;
	for(int i=1;i<=n;i++){
		sc(a[i]);
		if(a[i]>l&&a[i-1]<=l) ans++;
	}
	while(m--){
		int op, p, d;
		sc(op);
		if(op==0) printf("%d\n", ans);
		else{
			sc(p); sc(d);
			if(a[p]<=l&&a[p]+d>l){
				int c1=a[p-1]>l, c2=a[p+1]>l;
				ans = ans-c1-c2+1;
			}
			a[p] += d;
		}
	}
	return 0;
}

