#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define sc(x) scanf("%d",&x)
using namespace std;
typedef pair<int,int> pii;
const int maxn = 3e5+10;
int n, m, c[maxn];
pii a[maxn];
priority_queue<int> q;
int main(){
	int T; sc(T);
	for(int kase=1;kase<=T;kase++){
		while(q.size()) q.pop();
		sc(n); sc(m);
		for(int i=0;i<n;i++) sc(a[i].F), sc(a[i].S);
		for(int i=0;i<m;i++) sc(c[i]);
		sort(a,a+n); sort(c,c+m);
		int ans=0;
		for(int i=0,j=0;i<m;i++){
			while(j<n && a[j].F<=c[i]) q.push(-a[j].S), j++;
			while(q.size() && -q.top()<c[i]) q.pop();
			ans = max(ans, n-(int)q.size()+1);
			if(q.size()==0) break; 
			q.pop();
		}
		if(ans>n) printf("Case #%d: IMPOSSIBLE!\n",kase);
		else printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
