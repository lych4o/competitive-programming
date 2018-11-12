#include<bits/stdc++.h>
#define sll(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
#define ABS(x) ((x)<0?(-(x)):(x))
using namespace std;
typedef long long LL;
LL a1,a2,b1,b2,mx,mn;
inline LL f(LL x, LL y){return a1*a2*x*x+b1*b2*y*y+(b2*a1+b1*a2)*x*y;}
int n;
int main(){
	while(scanf("%lld",&a1)!=EOF){
		sll(b1);sll(a2);sll(b2);
		sc(n);
		for(int i=0;i<n;i++){
			int x,y; sc(x); sc(y);
			LL ff=f(x,y);
			if(!i) mx=mn=ff;
			else mx=max(mx,ff),mn=min(mn,ff);
		}
		printf("%lld\n",LL(ABS(1.0*(mx-mn)/(a2*b1-b2*a1))+0.5));
	}
	return 0;
}

