#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-8;
const db PI = acos(-1.0);
const LL mod = 1e9+7;

int main(){
	int T; sc(T);
	while(T--){
		int d; sc(d);
		if(d*d<4*d){
			printf("N\n");
			continue;
		}
		db dt=sqrt(d*d-4*d);
		db a=(d+dt)/2, b=(d-dt)/2;
		printf("Y %.9f %.9f\n",a,b);
	}
	return 0;
}
