#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const int maxn = 1900;
vector<int> prm;
int vis[maxn], tlen[maxn];
void sieve(){
	tlen[1]=1;
	for(int i=2;i<maxn;i++){
		int tmp=i;
		while(tmp>0) tlen[i]++,tmp/=10;
		if(!vis[i]){
			prm.pb(i);
		}
		for(int j=0;j<SZ(prm)&&i*prm[j]<maxn;j++){
			vis[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}
LL cnt[maxn], len[maxn];
void init(){
	sieve();
	for(int p: prm){
		for(int j=maxn-p-1;j>=0;j--){
			len[j+p] += len[j]+(2+tlen[p])*cnt[j];
			cnt[j+p] += cnt[j];
		}
		cnt[p]++;
		len[p] += 2+tlen[p];
	}
}
int main(){
	init();
	LL ans=-2;
	int dc=0;
	LL mx=0;
	for(int i=0;i<maxn;i++){
		ans += 2*cnt[i]+len[i];
		if(cnt[i]==0) dc++;
		mx = max(mx,2*cnt[i]+len[i]);
	}
	for(int i=0;i<10;i++){
		printf("cnt[%d]:%lld, len[%d]:%lld\n",i,cnt[i],i,len[i]);
	}
	LL tmp=ans,dd=0;
	while(tmp>0) dd++,tmp/=10;
	printf("pnum:%d, ans:%lld, dd:%lld, mx:%lld\n",SZ(prm),ans,dd,mx);
	printf("dc:%d, nn:%d\n",dc,maxn-dc);
	return 0;
}
