#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10, maxp = 25;
int n, q, a[maxn], go[maxn][maxp], nxt[maxp];

int main(){
	cin >> n >> q;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<maxp;j++) go[i][j] = nxt[j] = n+10;
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<maxp;j++) if((a[i]>>j)&1){
			for(int k=0;k<maxp;k++) if(nxt[j]<=n){
				go[i][k] = min(go[i][k], go[nxt[j]][k]);
			}
			go[i][j] = nxt[j] = i;
		}
		//for(int j=0;j<maxp;j++) printf("go[%d][%d]:%d\n",i,j,go[i][j]);
	}
	while(q--){
		int x, y, flg = 0; scanf("%d%d",&x,&y);
		for(int p=0;p<maxp;p++) if((a[y]>>p)&1){
			if(go[x][p] <= y) flg = 1;
		}
		if(!flg) puts("Fou");
		else puts("Shi");
	}
	return 0;
}
