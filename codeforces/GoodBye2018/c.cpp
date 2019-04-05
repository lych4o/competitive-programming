#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
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
const LL mod = 1e9+7;
const int maxn = 1e6+10;

vector<LL> ans;
vector<int> p, pw;
int n, m;
void dfs(int x, int now){
	if(x==sz(p)){
		LL cnt = m / now, bg = 1, ed = m-now+1;
		LL res = (bg+ed)*cnt/2;
		ans.pb(res);
	//	printf("ans[%d]:%I64d, bg:%I64d, ed:%I64d, cnt:%I64d\n"
		//		,now,res,bg,ed,cnt);
		return ;
	}
	int nxt=now;
	dfs(x+1, nxt);
	for(int i=1;i<=pw[x];i++){
		nxt *= p[x];
		dfs(x+1, nxt);
	}
}
int main(){
	cin >> n;  m = n;
	for(int i=2;i*i<=n;i++){
		if(n%i) continue;
		int cnt = 0;
		p.pb(i);
		while(n%i==0){
			cnt++;
			n /= i;
		}
		pw.pb(cnt);
		//printf("(%d,%d)\n",i,cnt);
	}
	if(n>1) pw.pb(1), p.pb(n);
	dfs(0,1);
	sort(ALL(ans));
	ans.erase(unique(ALL(ans)),ans.end());
	for(int i=0;i<sz(ans);i++){
		printf("%I64d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}
