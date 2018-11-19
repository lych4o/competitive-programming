

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
const int maxn = 3e5+10;
//const int maxn = 20;

vector<int> p;
int u[maxn],vis[maxn],sp[maxn];
void seve(){
	u[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i]){
			u[i]=-1;
			sp[i]=i;
			p.pb(i);
		}
		for(int j=0;j<SZ(p)&&i*p[j]<maxn;j++){
			u[i*p[j]]=-u[i];
			sp[i*p[j]]=p[j];
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				u[i*p[j]]=0;
				break;
			}
		}
	}
}

/*******comb***********/
const LL mod = 1e9+7;
const int maxc = 1e6+10;
int FAC[maxc], IVF[maxc], IV[maxc];
void init(){
    IV[1] = FAC[0] = FAC[1] = IVF[0] = IVF[1] = 1;
    for(int i = 2; i < maxc; i++){
        FAC[i] = 1LL*FAC[i-1]*i%mod;
        IV[i] = 1LL*(mod-mod/i)*IV[mod%i]%mod;
        IVF[i] = 1LL*IVF[i-1]*IV[i]%mod;
    }
}
LL comb(int x, int y){
    if(x < y) return 0;
    return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;
}/************comb*****/

int n, cnt[maxn], a[maxn];
void dfs(int num, int now){
	//printf("dfs(%d,%d)\n",num,now);
	if(num==1){
		cnt[now]++;
		return ;
	}
	int nxt=num, pp=sp[num], tot=0;
	while(nxt%pp==0) nxt/=pp, tot++;
	for(int i=0;i<=tot;i++){
		dfs(nxt, now);
		now *= pp;
	}
}
int check(int x){
	//printf("check(%d):\n",x);
	LL ret=0;
	for(int i=1;i<maxn;i++){
		ret += u[i]*comb(cnt[i],x);
		//printf("ret:%lld, u[%d]:%d, c(%d,%d):%lld\n",
			//	ret,i,u[i],cnt[i],x,comb(cnt[i],x));
	}
	ret = (ret%mod + mod)%mod;
	return  ret;
}
int main(){
	seve(); init();
	sc(n);
	for(int i=0;i<n;i++){
		int tmp; sc(tmp);
		//printf("i:%d\n",i);
		dfs(tmp,1);
	}
	for(int i=1;i<=7;i++){
		if(check(i)) return printf("%d\n",i), 0;
	}
	printf("-1\n");
	return 0;
}
