#include<bits/stdc++.h>
using namespace std;

int main(){
	double x, y;
	while(cin >> x >> y) cout << atan2(x,y)*180/acos(-1.0) << endl;
	return 0;
}
