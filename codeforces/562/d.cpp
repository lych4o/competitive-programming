#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 3e5+10, maxl = 20, INF = 0x3f3f3f3f;
typedef long long LL;
string s;
int vis[2][maxl], n;
int Find(int l){
	memset(vis, 0, sizeof(vis));
	int r = l+maxl, ret = INF;
	vector<int> v[2];
	for(int i=l;i<min(r,n);i++) v[s[i]-'0'].pb(i-l);
	for(int k=0;k<2;k++){
		for(int i=0;i<v[k].size();i++) vis[k][v[k][i]]=1;
		for(int i=0;i<v[k].size();i++) for(int j=i-1;j>=0;j--){
			if((v[k][i]+v[k][j])%2==0 && vis[k][(v[k][i]+v[k][j])/2])
				ret = min(ret, v[k][i]+l);
		}
	}
	return ret;
}
int main(){
	cin >> s;
	n = s.size();
	LL ans = 0;
	for(int i=0;i<n;i++){
		int x = Find(i);
		if(x < INF) ans += n-x;
	}
	cout << ans << endl;
	return 0;
}
