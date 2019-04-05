#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n;
char s[maxn];
int main(){
	int T; cin >> T;
	while(T--){
		cin >> n;
		scanf("%s", s);
		int ans = 0, flg = 0, tmp=0;
		for(int i=0;i<n;i++){
			if(s[i] == '>') break;
			tmp++;
		}
		ans = tmp; flg = 0; tmp = 0;
		for(int i=n-1;i>=0;i--){
			if(s[i] == '<') break;
			tmp++;
		}
		ans = min(ans, tmp);
		cout << ans << endl;
	}
	return 0;
}
