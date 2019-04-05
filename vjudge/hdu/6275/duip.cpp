#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long LL;
LL n;
bool f(LL a,LL b,LL c,LL n) {
	if (!a) return (((n+1)&(b/c))&1)>0;
	if (a>=c || b>=c) {
		LL sqr=(n&1) ?(n+1)/2*n :n/2*(n+1) ;
		return ((f(a%c,b%c,c,n)+(a/c)*sqr+(n+1)*(b/c))&1)>0;
	} else {
		LL m=(a*n+b)/c;
		return (((m*n)^f(c,c-b-1,a,m-1))&1)>0;
		}
}
int T;
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%lld",&n);
	LL ans=0,sqrtn=min(30000000ll,n);
	fo(i,1,sqrtn) ans^=n%i;
	for(LL i=sqrtn+1, j; i<=n; i=j+1) {
		j=n/(n/i);
		LL lim=n/i*(j-i)+n%j, ans1=0;
		for(LL k=1; k<=lim; k<<=1)
			ans1+=f(n/i,n%j,k,j-i)*k;
		ans^=ans1;
	}
	printf("%lld\n",ans);
	}
}
