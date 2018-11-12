#include<bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 1e6+10;
vector<int> p;
int u[maxn], vis[maxn];
void seve(){
	u[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i]) u[i]=-1, p.pb(i);
		for(int j=0;j<SZ(p)&&i*p[j]<maxn;j++){
			u[i*p[j]]=-u[i];
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				u[i*p[j]]=0;
				break;
			}
		}
	}
}
LL f[maxn];
LL F(LL x){
	if(x<maxn && f[x]>=0) return f[x];
	LL ret=0;
	for(LL i=1,j;i<=x;i=j+1){
		j=x/(x/i);
		ret = (ret+x/i*(j-i+1))%mod;
	}
	if(x<maxn) f[x]=ret;
	return ret;
}
int main(){
	seve();
	memset(f,-1,sizeof(f));
	int T; sc(T);
	for(int kase=1;kase<=T;kase++){
		LL n; sll(n);
		LL ans = 0;
		for(int i=1;i<=n/i;i++) if(u[i]){
			ans = (ans+u[i]*F(n/i/i))%mod;
		}
		printf("Case #%d: %lld\n",kase,(ans+mod)%mod);
	}
	return 0;
}
