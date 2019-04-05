#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int mod = 998244353;
const int maxn = 2e5+10;
int qpow(int x, int k){
	int ret=1;
	while(k>0){
		if(k&1) ret=1LL*ret*x%mod;
		x=1LL*x*x%mod;
		k>>=1;
	}
	return ret;
}
int n, a[maxn],vis[maxn],bit[maxn],fac[maxn],f[maxn];
vector<int> v, ps;
void add(int x, int v){for(int i=x;i<maxn;i+=i&-i) bit[i]+=v;}
int sum(int x){
	int ret = 0;
	for(int i=x;i>0;i-=i&-i) ret += bit[i];
	return ret;
}
int main(){
	sc(n); fac[0]=1; f[0]=0;
	for(int i=1;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		f[i] = (1LL*f[i-1]*i%mod + 1LL*(i-1)*i/2%mod*fac[i-1]%mod)%mod;
	}
	LL ans = 0;
	for(int i=1;i<=n;i++){
		sc(a[i]);
		if(a[i]==-1){
			ps.pb(i);
			continue;
		}
		vis[a[i]]=1;
		ans += sum(maxn-1)-sum(a[i]);
		ans %= mod;
		add(a[i],1);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) v.pb(i);
	sort(v.begin(),v.end());
	int cnt=0, m=v.size();
	ans = ans*fac[m]%mod;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){ cnt++; continue;}
		int nm = lower_bound(ALL(v),a[i])-v.begin();
		nm = m-nm;
		//printf("a[%d]:%d, cnt:%d, nm:%d\n",i,a[i],cnt,nm);
		ans += 1LL*nm*cnt%mod*fac[m-1]%mod;
		ans += 1LL*(m-nm)*(m-cnt)%mod*fac[m-1]%mod;
		ans %= mod;
		//printf("ans:%I64d\n",ans);
	}
	//printf("f[%d]:%I64d\n",m,f[m]);
	ans = (ans + f[m])%mod;
	//printf("ans:%I64d\n", ans);
	ans = ans*qpow(fac[m],mod-2)%mod;
	printf("%I64d\n", ans);
	return 0;
}
