#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, x;
	cin >> T;
	while(T--){
		cin >> x;
		int flg=0;
		for(int i=3;i<=360;i++){
			if(x*i%180==0 && (180-x)*i>=360){
				printf("%d\n",i);
				flg=1;
				break;
			}
		}
		if(!flg) puts("-1");
	}
	return 0;
}
