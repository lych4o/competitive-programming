#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int a[maxn], k[maxn], up = 5;
int main(){
	srand(time(NULL));
	int n = 6, q = 10;
	printf("%d\n", n);
	for(int i=1;i<=n;i++){
		printf("%d ", a[i]=rand()%up);
	}puts("");
	for(int i=1;i<n;i++){
		printf("%d ", k[i]=(a[i+1]-a[i]+rand()%up));
	}puts("");
	printf("%d\n", q);
	while(q--){
		int op = rand()%2, x = rand()%n + 1, y = rand()%n + 1;
		if(op==1 && x>y) swap(x,y);
		printf("%c %d %d\n", op?'s':'+', x, y);
	}
}
