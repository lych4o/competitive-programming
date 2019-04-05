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
const LL mod = 998244353;
const int maxn = 1e6+10;

LL qpow(LL x, LL k){
	LL ret=1;
	while(k>0){
		if(k&1) ret=ret*x%mod;
		x = x*x%mod;
		k>>= 1;
	}
	return ret;
}
LL fac[maxn], n;
int main(){
	cin >> n;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	LL ans = fac[n];
	for(int i=1;i<=n;i++){
		LL nm = fac[n]*qpow(fac[n-i], mod-2)%mod, len=fac[n-i];
		//printf("nm:%I64d, len:%I64d\n",nm,len);
		ans = (ans + nm*(len-1))%mod;
	}
	cout << ans << endl;
	return 0;
}
