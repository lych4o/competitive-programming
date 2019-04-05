#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 1e5+10;

LL gcd(LL a, LL b){
	if(!a) return b;
	return gcd(b%a, a);
}
LL get(LL a, LL b, LL c, LL d){
	//printf("get(%lld,%lld,%lld,%lld):%lld\n",a,c,b,d,max(min(b,d)-max(a,c), 0LL));
    return max(min(b,d)-max(a,c)+1, 0LL);
}
LL l1,r1,t1,l2,r2,t2;
int main(){
	cin >>l1>>r1>>t1>>l2>>r2>>t2;
	LL g=gcd(t1,t2);

	LL k = (l1-l2)/g, ans = 0;
	ans = max(ans, get(l1,r1,l2+k*g,r2+k*g));
	ans = max(ans, get(l1,r1,l2+k*g+g,r2+k*g+g));
	ans = max(ans, get(l1,r1,l2+k*g-g,r2+k*g-g));
	cout << ans << endl;
	return 0;
}

