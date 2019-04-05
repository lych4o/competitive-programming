#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s, t;
int n, k;
int main(){
	cin >> n >> k >> s >> t;
	LL ans=0, tot=1, flg=0;
	if(k==1) return printf("%d\n", n), 0;
	for(int i=0;i<n;i++){
		if(flg){
			tot = tot*2-2;
			if(s[i]=='a') tot++;
			if(t[i]=='b') tot++;
		}
		if(!flg&&s[i]!=t[i]) flg=1, tot=2;
		tot = min(tot, 1LL*k);
		ans += tot;
	}
	cout << ans << endl;
	return 0;
}
