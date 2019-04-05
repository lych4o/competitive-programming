#include<bits/stdc++.h>
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

int n, vis[20];
string s;
void dfs(int p, string pre){	
	if(p==n){
		s += pre;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1; char nxt=i+'0';
		dfs(p+1,pre+nxt); vis[i]=0; 
	}
}
int main(){
	for(int T=1;T<=10;T++){
		n = T; 
		memset(vis,0,sizeof(vis));
		s="";
		dfs(0,"");
		int ans=0;
		//cout<<s<<endl;
		for(int i=0;i+n<=s.size();i++){
			int flg=1;
			memset(vis,0,sizeof(vis));	
			for(int j=i;j<s.size()&&j<i+n;j++){
				if(vis[s[j]-'0']){
					flg=0;
					break;
				}
				vis[s[j]-'0']=1;
			}
			if(flg) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
