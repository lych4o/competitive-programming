#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	srand(time(NULL));
	int T = 1;
	while(T--){
		int n = 5;
		printf("%d\n", n);
		for(int i=1;i<=n;i++){
			printf("%d ", rand()%n + 1);
		}puts("");
	}
	return 0;
}
