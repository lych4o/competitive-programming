#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
int n, m, ans[30];
pii v[30];
int check(){
	for(int i=1;i<n*m;i++){
		int id = ans[i-1], ie = ans[i];
		int px = v[id].F, py = v[id].S,
			x = v[ie].F, y = v[ie].S;
		if(px==x || py==y || x-y==px-py || px+py==x+y) return 0;
	}
	return 1;
}
int main(){
	int T; cin >> T;
	for(int kase=1;kase<=T;kase++){
		cin >> n >> m;
		for(int i=0;i<n*m;i++) ans[i]=i;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) v[i*m+j] = mk(i,j);
		printf("Case #%d: ", kase);
		do{
			if(check()){
				printf("POSSIBLE\n");
				for(int i=0;i<n*m;i++){
					pii p = v[ans[i]];
					printf("%d %d\n", p.F+1, p.S+1);
				}
				break;
			}
		}while(next_permutation(ans, ans+n*m));
		printf("IMPOSSIBLE\n");
	}
	return 0;
}

