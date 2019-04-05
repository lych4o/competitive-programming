#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define sp putchar(' ')
#define ln puts("")
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 12;
int n, m, dp[maxn][1<<11], ip[1<<11];
bitset<102> c[maxn], d[maxn], vis;
void print(int x){
	for(int i=m-1;i>=0;i--) printf("%d",(x>>i)&1);
}
int main(){
	for(int i=0;i<11;i++) ip[1<<i] = i;
	int T; sc(T);
	for(int kase=1;kase<=T;kase++){
		sc(n); sc(m);
		for(int i=0;i<n;i++){
			int k; sc(k); c[i].reset();
			for(int j=0;j<k;j++){
				int tmp; sc(tmp);
				c[i].set(tmp-1);
			}
			//printf("c[%d]:",i); cout << c[i] << endl;
		}
		for(int i=0;i<m;i++){
			int k; sc(k); d[i].reset();
			for(int j=0;j<k;j++){
				int tmp; sc(tmp);
				d[i].set(tmp-1);
			}
			//printf("d[%d]:",i); cout << d[i] << endl;
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<n;i++)for(int j=0;j<(1<<m);j++)if(dp[i][j]>=0){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			//printf("dp[%d][",i); print(j); printf("]:%d\n",dp[i][j]);
			vector<int> p; for(int k=0;k<m;k++) if(!((j>>k)&1)) p.pb(k);
			for(int k=0;k<(1<<SZ(p));k++){
				vis.reset();
				int tmp=k, has=0;
				while(tmp>0){
					int pp=p[ip[tmp&-tmp]];
					has |= (1<<pp);
					vis |= d[pp];
					tmp -= tmp&-tmp;
				}
				//print(k); printf(":"); cout << vis;
				if(((~vis)&c[i]).none()){ 
					dp[i+1][j|has] = max(dp[i+1][j|has],dp[i][j]+1);
					//if(dp[i][j]+1>dp[i+1][j|has]) dp[i+1][j|has]=dp[i][j]+1;
					/*printf("dp[%d][%d]->dp[%d][%d]:max(%d,%d)\n",
					i,j,i+1,j|has,dp[i+1][j|has],dp[i][j]+1);*/
				}
				//cout << endl;
			}
		}
		int mx=0;
		for(int i=0;i<(1<<m);i++) mx=max(mx,dp[n][i]);
		printf("Case #%d: %d\n",kase,mx);
	}
	return 0;
}
