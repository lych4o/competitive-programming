#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef double db;
const int maxn = 1005;
const int maxc = 12;
const int maxm = 51;
db dp[maxn][maxc][maxc][maxc], C[maxm][maxm];
int n, d, c, a[2][12], cnt;
int main(){
	C[0][0]=1;
	for(int i=1;i<maxm;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	sc(n); sc(d); sc(c);
	for(int i=0;i<c;i++) sc(a[0][i]);
	for(int i=0;i<c;i++){
		sc(a[1][i]);
		for(int j=0;j<c;j++) if(a[1][i]==a[0][j]) cnt++;
	}
	memset(dp,0,sizeof(dp));
	dp[0][cnt][c-cnt][c-cnt]=1;
	for(int i=0;i<maxn-1;i++) for(int j=0;j<=c;j++)
	for(int k=0;k<=c;k++) for(int h=0;h<=c;h++) if(dp[i][j][k][h]>0){
		if(j==0 && (k==0||h==0)) continue;
		int rn=n-j-k-h; if(rn<0) continue;
		for(int x=min(d,j);x>=0;x--)
		for(int y=min(d-x,k);y>=0;y--)
		for(int z=min(d-x-y,h);z>=0;z--){
			int rs=d-x-y-z;
			//printf("%d:(%d,%d,%d)-(%d,%d,%d)=(%d,%d,%d):%.6f\n",
			//	i,j,k,h,x,y,z,j-x,k-y,h-z,C[rn][rs]*C[j][x]/C[n][d]*C[k][y]*C[h][z]);
			dp[i+1][j-x][k-y][h-z]+=C[rn][rs]*C[j][x]/C[n][d]*C[k][y]*C[h][z]*dp[i][j][k][h];
		}
	}
	db ans=0;
	for(int i=1;i<maxn;i++) for(int j=0;j<=c;j++) for(int k=0;k<=c;k++){
		if((j==0)||(k==0)) ans += i*dp[i][0][j][k];
	}
	printf("%.6f\n",ans);
	return 0;
}
