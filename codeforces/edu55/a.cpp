#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
typedef long long LL;
int n,x,y,d;
int main(){
	int T; sc(T);
	while(T--){
		sc(n);sc(x);sc(y);sc(d);
		if((x-y)%d==0){
			printf("%d\n",abs(x-y)/d);
			continue;
		}
		int ans=n+10;
		if((n-y)%d==0){
			ans = min(ans, (n-x+d-1)/d + (n-y)/d);
		}
		if((1-y)%d==0){
			ans = min(ans, (x-1+d-1)/d + (y-1)/d);
		}
		if(ans>n) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
