#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const LL mod = 998244353;
const int maxn = 3e5+10;
LL n, k, a[maxn];

LL qpow(LL x, LL k){
	LL ret = 1;
	while(k>0){
		if(k&1) ret = ret*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return ret;
}
LL f[maxn], g[maxn], h[maxn], p[maxn];
vector<int> v;
LL calc(){
	//printf("calc():");
	//for(int i=0;i<v.size();i++) printf("%d ", v[i]); puts("");
	LL ret = 1;
	int pre = -1, m = v.size();
	for(int i=0;i<m;i++){
		if(v[i] != -1){
			if(pre == -1) ret = ret*g[i-pre-1]%mod;
			else if(v[i] == v[pre]) ret = ret*h[i-pre-1]%mod;
			else if(v[i] != v[pre]) ret = ret*p[i-pre-1]%mod;
			pre = i;
		}
	}
	if(pre != -1) ret = ret*g[m-1-pre]%mod;
	else ret = ret*f[m]%mod;
	//printf("ret:%lld\n", ret);
	v.clear();
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	f[0] = 1;
	for(int i=1;i<=n;i++){
		f[i] = k*qpow(k-1,i-1)%mod;
	}
	for(int i=0;i<=n;i++) g[i] = qpow(k-1,i)%mod;
	h[0] = 0; h[1] = k-1; p[0] = 1; p[1] = k-2;
	for(int i=2;i<=n;i++){
		h[i] = (p[i-2]*(k-1)%mod*(k-2)%mod + h[i-2]*(k-1)%mod)%mod;
		LL tmp = (k*k - 3*k +3)%mod;
		p[i] = (p[i-2]*tmp%mod + h[i-2]*(k-2)%mod)%mod;
	}
	//for(int i=0;i<=n;i++) printf("(%lld, %lld)\n", h[i], p[i]);
	for(int i=1;i<=n;i+=2) v.pb(a[i]);
	LL ans = calc();
	for(int i=2;i<=n;i+=2) v.pb(a[i]);
	ans = ans*calc()%mod;
	cout << ans << endl;
	return 0;
}
