#include<bits/stdc++.h>
using namespace std;

char str[30];
int run(string s){
	for(int i=0;i<s.size();i++) str[i]=s[i];
	str[s.size()]=0;
	return system(str);
}
int main(){
	for(int T=1;;T++){
		run("gen>f.in");
		run("f<f.in>f.out");
		run("f2<f.in>f1.out");
		if(run("diff f.out f1.out")){
			printf("WA on test %d\n",T);
			break;
		}else printf("AC on test %d\n",T);
	}
	return 0;
}
