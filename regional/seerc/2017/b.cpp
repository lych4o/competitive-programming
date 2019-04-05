#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int mod = 1e9+7;
const int maxn = 2e6+10;
int s[maxn], dp[maxn], sum[maxn], n, m;
int main(){
	sc(n); sc(m); n++;
	for(int i=0;i<m;i++){
		int tmp; sc(tmp);
		s[tmp]++;
	}
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	dp[0] = 1; sum[0-0+n] = 1;
	for(int i=1;i<=n;i++) if(s[i]==s[i-1]){
		dp[i] = sum[s[i-1]-(i-1)+n];
		sum[s[i]-i+n] = (sum[s[i]-i+n] + dp[i])%mod;
	}
	printf("%d\n", dp[n]);
	return 0;
}
