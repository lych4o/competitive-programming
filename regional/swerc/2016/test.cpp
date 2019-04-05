#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	while(cin >> x >> y){
		cout << atan2(y,x)*180.0/acos(-1.0) << endl;
	}
}
