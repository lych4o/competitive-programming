#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m, a[maxn];
int check(int x){
	int pre = 0;
	for(int i=0;i<n;i++){
		if((pre-a[i]+m)%m <= x) continue;
		else if(a[i] >= pre) pre = a[i];
		else if(a[i] < pre) return 0;
	}
	return 1;
}
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	int L = -1, R = m+1;
	while(L+1<R){
		int mid = (L+R)>>1;
		if(check(mid)) R = mid;
		else L = mid;
	}
	cout << R << endl;
	return 0;
}
