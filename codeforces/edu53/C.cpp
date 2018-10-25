#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
const int maxn = 2e5+10;

inline int ABS(int x){
	return x < 0 ? -x : x;
}
inline int id(char c){
	if(c=='U') return 0;
	if(c=='D') return 1;
	if(c=='L') return 2;
	if(c=='R') return 3;
}
int n, tx, ty, x, y, dx[maxn], dy[maxn];
inline void mv(int ID){
	if(ID==0) y++;
	if(ID==1) y--;
	if(ID==2) x--;
	if(ID==3) x++;
	//printf("mv(%d):(%d,%d)\n",ID,x,y);
}
inline int dis(){
	return ABS(x-tx)+ABS(y-ty);
}
inline int dis(int xx, int yy){
	return ABS(xx-tx)+ABS(yy-ty);
}
int check(int l, int r){
    int xx=x-dx[r]+dx[l-1], yy=y-dy[r]+dy[l-1];
    //printf("check(%d,%d):(%d,%d)\n",l,r,xx,yy);
    if(dis(xx,yy) > r-l+1 || ((dis(xx,yy)-r+l-1)%2)) return 0;
    return 1;
}
char s[maxn];
int main(){
	sc(n);
	scanf("%s", s+1); sc(tx); sc(ty);
	if(ABS(tx)+ABS(ty) > n || ((ABS(tx)+ABS(ty)-n)%2)){
		printf("-1\n");
		return 0;
	}
	x=0,y=0;
	int ans=n;
	for(int i=1;i<=n;i++){
		int xx=x,yy=y;
		mv(id(s[i]));
		dx[i]=dx[i-1]+x-xx;
		dy[i]=dy[i-1]+y-yy;
		//printf("d[%d]:(%d,%d)\n",i,dx[i],dy[i]);
	}
	x=0;y=0;
	for(int i=1;i<=n;i++) mv(id(s[i]));
	//puts("");
	if(dis()==0) ans = 0;
	for(int i=1;i<=n;i++){
		int l=i-1, r=n+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(i,mid)) r = mid;
			else l = mid;
		}
		//printf("l:%d, r:%d\n",l,r);
		if(r<=n) ans = min(ans, r-i+1);
	}
	printf("%d\n", ans);
	return 0;
}
