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
const int maxn = 1e6+10;

int n, k;
int main(){
	cin >> n >> k;
	int l = k-1, r = n-k;
	if(l==0 || r==0){
		printf("%d\n", n*3);
		return 0;
	}
	int ans = l+r+min(l,r) + 2*n + 1;
	cout << ans << endl;
	return 0;
}
