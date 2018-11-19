#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-8;
const db PI = acos(-1.0);
const LL mod = 1e9+7;

int n;
string s, ans;
int main(){
	cin >> n >> s;
	ans = "";
	for(int i=0;i<SZ(s)-1;i++){
		if(s[i]>s[i+1]){
			ans = s.substr(0,i)+s.substr(i+1);
			break;
		}
	}
	if(ans=="") ans=s.substr(0,SZ(s)-1);
	cout << ans << endl;
	return 0;
}
