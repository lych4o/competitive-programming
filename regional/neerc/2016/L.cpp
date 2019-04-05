#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define F first
#define S second
#define mk make_pair
#define pLL pair<LL,LL>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const int maxn = 2100, maxp=400, maxl=1e6+10;
vector<int> prm;
vector<char> ch[maxn];
int nop[maxn], tlen[maxn];
void sieve(){
	nop[1]=1;
	for(int i=2;i<maxn;i++){
		int tmp=i;
		if(!nop[i]){
			while(tmp>0) tlen[i]++,ch[i].pb(tmp%10+'0'),tmp/=10;
			prm.pb(i);
		}
		for(int j=0;j<SZ(prm)&&i*prm[j]<maxn;j++){
			nop[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}
pLL dp[maxp][maxn];
int vis[maxp][maxn];
pLL cal(int x, int sum){
	//printf("cal(%d,%d):",x,sum);
	if(sum<0) return mk(0,0);
	if(vis[x][sum]) return dp[x][sum];
	vis[x][sum]=1;
	if(sum==0) return dp[x][sum]=mk(1,2);
	if(prm[x]>sum) return dp[x][sum]=mk(0,0);
	pLL p1=cal(x+1,sum-prm[x]),p2=cal(x+1,sum);
	return dp[x][sum]=mk(p1.F+p2.F,p1.S+p1.F*(tlen[prm[x]]+2)+p2.S);
}
LL cur,a,b,pre;
vector<int> v;
char s[maxl];
void pc(char c){
	//printf("pc(%c)\n",c);
	if(cur>=a&&cur<=b) s[cur-a]=c; 
	cur++;
}
void print(){
	//printf("print(");
	//for(int i=0;i<SZ(v);i++) printf("%d ",v[i]); printf(")\n");
	pc(','); pc(' '); pc('[');
	for(int i=0;i<SZ(v);i++){
		if(i>0) pc(','), pc(' ');
		for(int j=tlen[v[i]]-1;j>=0;j--){
			pc(ch[v[i]][j]);
		}
	}pc(']');
}
void solve(int x, int sum){
	//printf("solve(%d,%d)\n",x,sum);
	if(sum<0||cur>b) return;
	if(sum==0){
		print();
		return ;
	}
	if(prm[x]>sum) return;
	v.pb(prm[x]);
	pre += tlen[prm[x]]+2;
	pLL L=cal(x+1,sum-prm[x]),R=cal(x,sum);

	LL len=pre*L.F+L.S;
	if(cur+len>=a && cur<=b) solve(x+1,sum-prm[x]);
	else cur+=len;
	
	v.pop_back();
	pre -= tlen[prm[x]]+2;
	len=pre*R.F+R.S;
	if(cur+len>=a && cur<=b) solve(x+1,sum);
	else cur+=len;
}
void debug(){
	int x,y; 
	while(cin>>x>>y){
		printf("x:%d, y:%d\n",x,y);
		//pLL res=cal(x,y);
		printf("cal(%d,%d):(%lld,%lld)\n",x,y,cal(x,y).F,cal(x,y).S);
	}
}
int main(){
	freopen("list.in","r",stdin);
	freopen("list.out","w",stdout);
	sieve();
	//debug();
	cin >> a >> b; pre=0; cur=-1;
	for(int i=2;i<maxn && cur<=b;i++){
		pLL u=cal(0,i);
		if(cur+u.S >= a) solve(0,i);
		else cur += u.S;
	}
	s[b-a+1]='\0';
	printf("%s\n",s);
	return 0;
}
