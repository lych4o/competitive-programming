#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int a[maxn], n, b[maxn];

int main(){
	cin >> n;
	for(int i=0;i<n;i++) sc(a[i]), sc(b[i]);
	int k; sc(k);
	for(int i=0;i<n;i++) if(k >= a[i] && k <= b[i])
		return printf("%d\n", n-i), 0;
	return 0;
}
