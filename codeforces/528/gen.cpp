#include<bits/stdc++.h>
using namespace std;

char s[100], a[100], b[100];
inline int rd(int k){
	return (rand()%k)+'a';
}
int main(){
	srand(time(NULL));
	int T = 100; printf("%d\n",T);
	while(T--){
		int n = 10, k = 5, len = rand()%n;
		for(int i=0;i<n;i++) s[i] = (rand()%k)+'a';
		for(int i=0;i<len;i++){
			char c = rd(k);
			a[i] = b[i] = c;
		}
		if(len==n) continue;
		char c1='a', c2='a';
		while(c1>=c2) c1=rd(k), c2=rd(k);
		a[len]=c1; b[len]=c2;
		for(int i=len+1;i<n;i++){
			a[i]=rd(k); b[i]=rd(k);
		}
		a[n]=b[n]=s[n]='\0';
		printf("%d\n%s\n%s\n%s\n",k,s,a,b);
	}
	return 0;
}
