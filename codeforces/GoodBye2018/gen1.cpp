#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL RAND(){
	LL a=rand(),b=rand();
	return a<<31+b;
}
int main(){
	srand(time(NULL));
	int n = 6;
	printf("%d\n", n);
	LL mx = 1e12;
	for(int i=0;i<n;i++){
		//printf("%lld ", (RAND()%mx)+1);
		printf("%lld ", (rand()%10)+1);
	}puts("");
	printf("G");
	for(int i=1;i<n;i++){
		int x=rand()%3;
		if(x==0) printf("G");
		else if(x==1) printf("L");
		else printf("W");
	}
	return 0;
}
