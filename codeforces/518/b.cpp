#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("I64d",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1e6+10;

int main(){
	LL ans = 1, b;
	cin >> b;
	for(LL i=2;i*i<=b;i++){
		if(b%i==0){
			int cnt=0;
			while(b%i==0) b/=i, cnt++;
			ans *= (cnt+1);
		}
	}
	if(b>1) ans *= 2;
	cout << ans << endl;
	return 0;
}
