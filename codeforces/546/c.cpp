#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const LL mod = 1e9+7;
const int maxn = 510;

int a[maxn][maxn], b[maxn][maxn], n, m;
vector<int> va, vb;
int main(){
	sc(n); sc(m);
	for(int i = 0; i < n;i ++) for(int j=0;j<m;j++) sc(a[i][j]);
	for(int i = 0; i < n;i ++) for(int j=0;j<m;j++) sc(b[i][j]);
	for(int i=0;i<n+m-1;i++){
		va.clear(); vb.clear();
		for(int r = max(0,i-m+1);i-r>=0 && r<n; r++){
			va.pb(a[r][i-r]); vb.pb(b[r][i-r]);
		}
		sort(ALL(va)); sort(ALL(vb));
		for(int j=0;j<va.size();j++){
			if(va[j]!=vb[j]) return printf("NO\n"), 0;
		}
	}
	printf("YES\n");
	return 0;
}
