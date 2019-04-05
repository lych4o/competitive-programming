#include<bits/stdc++.h>
using namespace std;

string a, b;
int main(){
	cin >> a;
	int l=0, r=a.size()-1, now=1;
	if((r+1)%2) now = 0;
	while(l<=r){
		if(!now) b += a[l++];
		else b += a[r--];
		now ^= 1;
	}
	for(int i=b.size()-1;i>=0;i--){
		cout << b[i];
	}
	return 0;
}
