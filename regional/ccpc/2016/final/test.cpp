#include<bits/stdc++.h>
using namespace std;

int main(){
	int ans=0;
	for(int i=0;i<(1<<10);i++){
		int tmp=i,cnt=0;
		while(tmp>0)tmp-=tmp&-tmp,cnt++;
		ans += (1<<cnt);
	}
	printf("%d\n",ans);
	return 0;
}
