#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,x,b,y;
	cin >> n >> a >> x >> b >> y;
	a--; x--; b--; y--;
	for(;;){
		if(a==b) return cout<<"YES", 0;
		if(a==x || b==y) break;
		a = (a+1)%n;
		b = (b+n-1)%n;
	}
	cout <<"NO";
	return 0;
}
