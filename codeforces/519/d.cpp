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
const int maxn = 1e6+10;
int n, m, a[15][maxn], p[15], ps[maxn][15];
int main(){
	sc(n); sc(m);
	for(int i=1;i<=m;i++)for(int j=0;j<n;j++){
		sc(a[i][j]),ps[a[i][j]][i]=j;
	}
	LL ans = 0;
	for(int l=0,d;l<n;l+=d){
		//printf("l:%d\n",l);
		for(int i=2;i<=m;i++) p[i]=ps[a[1][l]][i];
		for(d=0;l+d<n;d++){
			int flg=1;
			for(int i=2;i<=m;i++){
				if(p[i]+d>=n || a[i][p[i]+d]!=a[1][l+d]){
					flg=0;
					break;
				}
			}
			if(!flg) break;
		}
		ans += 1LL*d*(d+1)/2;
	}
	cout << ans << endl;
	return 0;
}
