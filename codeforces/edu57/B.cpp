#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;
char s[maxn];
LL n;
int main(){
	cin >> n;
	scanf("%s",s);
	LL a,c=n;
	for(a=0;a<n&&s[a]==s[0];a++){}
	for(int i=n-1;i>=0;i--){
		if(s[i]!=s[n-1]){
			c=n-1-i;
			break;
		}
	}
	if(s[0]==s[n-1]){
		if(a==n) cout << n*(n+1)/2%mod << endl;
		else cout << (a+1)*(c+1)%mod << endl;
	}else{
		cout << a + c + 1<< endl;
	}
	return 0;
}
