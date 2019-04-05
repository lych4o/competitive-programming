#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int n, a[maxn];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	int ans = 0, mx = 0;
	for(int i=1, j;i<=n;i=j){
		j = i;
		while(j<=n){
			mx = max(a[j++], mx);
			if(j-1 >= mx) break;
		}
		//printf("i:%d, j:%d\n",i,j);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
