#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 2e5+10;
int a[maxn], n, vis[maxn];
int main(){
	sc(n);
	for(int i=n;i>=1;i--){
		sc(a[i]);
	}
	int m=n, tt;
	for(int i=1;i<=n;i++){
		sc(tt);
		int cnt=0;
		if(vis[tt]){
			printf("0 ");
			continue;
		}
		else while(m>0 && a[m]!=tt){
			cnt++;
			vis[a[m]]=1;
			m--;
		}
		vis[a[m--]] = 1; cnt++;
		printf("%d ", cnt);
	}
	return 0;
}
