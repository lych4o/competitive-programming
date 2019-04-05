#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int maxn = 3e5+10;
int n, k;
pii a[maxn];
priority_queue<int> q;
int main(){
	sc(n); sc(k);
	for(int i=0;i<n;i++) sc(a[i].S), sc(a[i].F);
	sort(a, a+n);
	LL sum = 0, ans = 0;
	for(int i=n-1;i>=0;i--){
		sum += a[i].S;
		q.push(-a[i].S);
		if(q.size() == k+1){
			sum += q.top();
			q.pop();
		}
		ans = max(ans, a[i].F*sum);
	}
	cout << ans << endl;
	return 0;
}
