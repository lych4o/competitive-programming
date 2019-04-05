#include<bits/stdc++.h>
using namespace std;

const int maxn=10;
int main(){
	srand(time(NULL));
	int n = 10;
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%d %d\n", rand()%maxn+1, rand()%maxn+1);
	}
	return 0;
}
