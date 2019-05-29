#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 1e6+10;
int n, m, a[maxn], b[maxn];

int check(int x){
	vector<int> v;
	for(int i=0;i<n;i++){
		if(a[i]!=x && b[i]!=x) v.pb(i);
	}
	if(v.size()==0) return x;
	int xx = a[v[0]], yy = b[v[0]], flg = 1;
	for(int p: v){ if(a[p]!=xx&&b[p]!=xx) flg=0; }
	if(flg) return xx;
	flg=1;
	for(int p: v){ if(a[p]!=yy&&b[p]!=yy) flg=0; }
	if(flg) return yy;
	return 0;
}
int main(){
	cin >> m >> n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	int x=0, y=0;
	if(check(a[0]) || check(b[0])) printf("YES\n");
	else printf("NO\n");
	return 0;
}
