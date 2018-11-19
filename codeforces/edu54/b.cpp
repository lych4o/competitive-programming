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

LL n;
int main(){
	cin >> n;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0){
			if(i==2) return cout << n/2<<endl, 0;
			else return cout << (n-i)/2+1 << endl, 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
