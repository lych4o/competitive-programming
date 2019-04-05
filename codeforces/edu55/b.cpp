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
const int maxn = 1e5+10;
int n, m, a[maxn], tot;
char s[maxn];
int main(){
	sc(n);
	m=0;
	scanf("%s",s);
	if(s[0]=='S') a[m++] = 0;
	for(int i=0,j;i<n;i=j){
		j = i+1;
		while(j<n && s[j]==s[i]) j++;
		a[m++] = j-i;
	}
	int ans=0;
	for(int i=0;i<m;i++){
		if(i%2) continue;
		tot += a[i];
		ans = max(ans,a[i]);
	}
	for(int i=0;i<m;i++){
		if(i%2==0){
			if(a[i]<tot) ans=max(ans,a[i]+1);
		}else{
			if(i+1>=m) continue;
			if(a[i]==1){
				if(a[i+1]+a[i-1]<tot) ans=max(ans,a[i-1]+a[i+1]+1);
				else ans=max(ans,a[i-1]+a[i+1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
