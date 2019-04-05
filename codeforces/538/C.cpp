#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
LL n, x;
vector<pll> v;
int main(){
	cin>>n>>x;
	for(LL i=2;i*i<=x;i++){
		if(x%i) continue;
		int cnt = 0;
		while(x%i==0) x /= i, cnt++;
		v.pb(mk(i,cnt));
	}
	if(x>1) v.pb(mk(x,1));
	LL ans = 1e18+10;
	for(int i=0;i<v.size();i++){
		LL a = v[i].F, b = v[i].S, cnt = 0, nm = n/a;
		while(nm>0){
			cnt += nm;
			nm /= a;
		}
		ans = min(ans, cnt/b);
	}
	cout << ans << endl;
	return 0;
}
