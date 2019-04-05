#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int maxn = 3e5+10;
int n;
int main(){
	cin >> n;
	LL ans = 0;
	for(int i=3;i<=n;i++){
		ans += i*(i-1);
	}
	cout << ans << endl;
	return 0;
}
