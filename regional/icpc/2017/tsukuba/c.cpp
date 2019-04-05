#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
LL a[maxn], n, t;
int main(){
	sll(n); sll(t);
	LL a1=0, k=0;
	for(int i=1;i<=n;i++){
		sll(a[i]);
		a1 += a[i];
		if(a[i]>k) k=a[i];
		if(t<a1){
			printf("%d\n", 1);
			continue;
		}
		LL tt = (t-a1)/k;
		printf("%lld\n",2+tt);
	}
	return 0;
}
