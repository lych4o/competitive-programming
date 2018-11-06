#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
using namespace std;
typedef long long LL;
LL f(LL a, LL b, LL c, LL n){
	if(!a) return (b/c)*(n+1);
	if(a>=c||b>=c) return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	LL m=(a*n+b)/c, v=f(c,c-b-1,a,m-1);
	return n*m-v;
}
int main(){
	int T; sc(T);
	while(T--){
		LL n; sll(n);
		const LL lych = 4e7+10;
		LL ans = 0;
		for(int i=min(n,lych);i>=1;i--) ans ^= (n%i);
		if(n <= lych){
			printf("%lld\n", ans);
			continue;
		}
        for(LL i=lych+1,j;i<=n;i=j+1){
			j = n/(n/i);
			LL tmp = 0, mx=n/i*(j-i)+n%j;
			for(LL k=1;k<=mx;k<<=1)
				tmp |= (f(n/i,n%j,k,j-i)&1)*k;
			ans ^= tmp;
        }
        printf("%lld\n",ans);
	}
	return 0;
}

