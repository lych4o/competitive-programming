#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;

int cnt[30], n;
string s;

int check(int len){
	for(int i=0;i<30;i++){
		if(cnt[i]>len/2) return 0;
	}
	return 1;
}
int main(){
	cin >> n >> s;
	for(int l=0;l<n;l++){
		memset(cnt,0,sizeof(cnt));
		for(int r=l;r<n;r++){
			cnt[s[r]-'a']++;
			if(check(r-l+1)){
				cout << "YES"<<endl<<s.substr(l,r-l+1)<< endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
