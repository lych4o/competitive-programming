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
const int maxn = 1e6+10;
int n, c, a[maxn], mx[maxn], sum[maxn];
int main(){
	sc(n); sc(c);
	for(int i=1;i<=n;i++) sc(a[i]);
	int ans = 0, cnt = 0;
	for(int i=1;i<=n;i++) if(a[i]==c) ans++, cnt++;
	for(int i=1;i<=n;i++){
		mx[a[i]] = max(mx[a[i]],sum[c]-sum[a[i]]);
		sum[a[i]]++;
		ans = max(ans, cnt + sum[a[i]]-sum[c]+mx[a[i]]);
	}
	cout << ans << endl;
	return 0;
}
