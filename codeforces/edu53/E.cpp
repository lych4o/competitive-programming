#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define pLL pair<LL, LL>
#define fi first
#define se second
#define sp putchar(' ')
#define ln puts("")
#define pr print
using namespace std;
typedef long long LL;
const LL mod = 998244353;
const int maxn = 2e5+10;

LL dig[20], L, R, k, len, sum[20][2050], f[20][2050], pw[20];
int vis[20][1100];

inline int cont(int x){
	int ans=0;
	while(x>0) x-=x&-x, ans++;
	return ans;
}
LL solve(LL x){
	len = 0;
	LL tmp = x;
    while(tmp>0){
		dig[len++] = tmp%10;
		tmp /= 10;
    }
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
    f[0][0]=1;
    for(int p=0;p+1<20;p++) for(int st=0;st<(1<<10);st++){
    	if(!f[p][st]&&!sum[p][st]) continue;
        for(int i=0;i<=9;i++){
			int ns = st|(1<<i);
			if(cont(ns)>k) continue;
            sum[p+1][ns] = (sum[p+1][ns]+i*f[p][st]%mod*pw[p]+sum[p][st])%mod;
			f[p+1][ns] = (f[p+1][ns]+f[p][st])%mod;
        }
    }

    LL ans = 0;
    for(int i=1;i<dig[len-1];i++){
		for(int nst=0;nst<(1<<10);nst++){
			int ns=nst|(1<<i);
			if(cont(ns)>k) continue;
            ans += i*pw[len-1]%mod*f[len-1][nst]%mod;
            ans = (ans + sum[len-1][nst])%mod;
		}
    }
	for(int p=len-2;p>=0;p--)for(int nst=0;nst<(1<<10);nst++){
	if(f[p][nst]||sum[p][nst]) for(int i=1;i<10;i++){
			int ns=(nst)|(1<<i);
			if(cont(ns)>k) continue;
			ans += i*pw[p]%mod*f[p][nst]%mod;
			ans = (ans + sum[p][nst])%mod;
		}
	}
	LL st=(1<<(dig[len-1])), psum=dig[len-1]*pw[len-1]%mod;
	for(int p=len-2;p>=0;p--){
		for(int nst=0;nst<(1<<10);nst++) if(f[p][nst]||sum[p][nst])
		for(int i=0;i<dig[p];i++){
			int ns=(nst)|(st)|(1<<i);
			if(cont(ns)>k) continue;
			ans += (psum+i*pw[p]%mod)*f[p][nst]%mod;
			ans = (ans + sum[p][nst])%mod;
		}
		st |= (1<<dig[p]);
		psum += dig[p]*pw[p]%mod;
		psum %= mod;
	}
	return ans;
}
int main(){
	pw[0]=1;
	for(int i=1;i<20;i++) pw[i]=pw[i-1]*10%mod;
	cin >> L >> R >> k;
	LL ans = solve(R+1)-solve(L);
	cout << (ans%mod+mod)%mod << endl;
	return 0;
}
