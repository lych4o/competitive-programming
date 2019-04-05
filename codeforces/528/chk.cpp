#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e6+10;
char s[maxn], a[maxn], b[maxn], tb[30], tmp[30];
int k,n;
inline int id(char c){return c-'a';}
int cmp(char* x, char* y){
	for(int i=0;i<n;i++){
		if(x[i]<y[i]) return -1;
		if(x[i]>y[i]) return 1;
	}
	return 0;
}
int main(){
	int T; sc(T);
	for(int kase=1;kase<=T;kase++){
		scanf("%d%s%s%s%s",&k,s,a,b,tmp);
		if(tmp[0]=='N') continue;
		scanf("%s",tb);
		n = strlen(a);
		for(int i=0;i<n;i++){
			s[i]=tb[id(s[i])];
		}
		//printf("s:%s\n",s);
		int flg=1;
		if(cmp(s,a)<0) flg=0;
		if(cmp(s,b)>0) flg=0;
		if(flg==0) printf("Wa on test %d\n",kase);
	}
	return 0;
}
