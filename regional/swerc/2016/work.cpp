#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
using namespace std;

char s[100];
void tr(string str){
	for(int i=0;i<SZ(str);i++)
		s[i]=str[i];
	s[SZ(str)]='\0';
}
int run(string str){
	tr(str);
	return system(s);
}
int main(){
	for(int t=1;;t++){
		run("gen>b.in");
		run("b<b.in>b.out");
		run("b1<b.in>b1.out");
		if(run("diff b.out b1.out")){
			printf("WA on test %d\n",t);
			break;
		}else printf("AC on test %d\n", t);
	}
	return 0;
}
