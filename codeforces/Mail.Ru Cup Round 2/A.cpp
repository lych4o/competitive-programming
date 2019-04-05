#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%lld",&x)
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
const int maxn = 1e3+10;

int v1[maxn], v2[maxn], n, s, ok;
int main(){
	sc(n); sc(s);
	for(int i=1;i<=n;i++) sc(v1[i]);
	for(int i=1;i<=n;i++) sc(v2[i]);
	if(!v1[1]){
		printf("NO\n");
		return 0;
	}
	if(v1[s]){
		printf("YES\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i>=s && v1[i] && v2[i] && v2[s]){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO");
	return 0;
}

