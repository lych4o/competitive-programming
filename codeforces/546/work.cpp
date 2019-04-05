#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int main(){
	int kase = 0;
	while(++kase){
		system("gen > e.in");
		system("e<e.in>e.out");
		system("e1<e.in>e1.out");
		if(system("fc e.out e1.out")){
			printf("WA on test %d\n",kase);
			break;
		}else printf("AC on test %d\n", kase);
	}
	return 0;
}
