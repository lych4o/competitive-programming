#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char s[maxn], tb[26];
int id(char c){
	return c-'a';
}
int main(){
	while(scanf("%s%s",tb,s)!=EOF){
		int n=strlen(s);
		for(int i=0;i<n;i++){
			int u=id(s[i]),v=tb[u];
			//printf("u:%d, v:%d\n",u,v);
			s[i]=v;
		}
		printf("%s\n",s);
	}
}
