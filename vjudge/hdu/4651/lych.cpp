#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 1e5+10;
LL p[maxn];
void init(){
	p[0]=1;
	for(int i=1;i<maxn;i++){
		for(int j=1;i-(3LL*j*j-j)/2>=0;j++){
			//int p1=(3*j*j-j)/2,p2=(3*j*j+j)/2;
			//printf("p1:%d, p2:%d\n", p1,p2);
			int k=j%2?1:-1;
			p[i] += k*p[i-(3LL*j*j-j)/2]; 
			if(i-(3LL*j*j+j)/2>=0) p[i] += k*p[i-(3LL*j*j+j)/2];
		}
		p[i] = (p[i]%mod+mod)%mod;
	}
}
int main(){
	init();
	int T; sc(T);
	while(T--){
		int n; sc(n);
		printf("%d\n",p[n]);
	}
	return 0;
}
