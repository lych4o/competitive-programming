#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k;
int main(){
	cin >> n >> k;
	LL ans = 1e18;
	for(int i=1;i<k;i++){
		if(n%i==0){
			ans = min(ans, n/i*k+i);
		}
	}
	cout << ans << endl;
	return 0;
}
