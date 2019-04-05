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

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int ans = 3*a+3;
	ans = min(ans, 3*b);
	ans = min(ans, 3*c-3);
	cout << ans << endl;
	return 0;
}
