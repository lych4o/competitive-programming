#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-8;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 3e5+10;
int n, k, a[maxn][2], st[maxn];
int main(){
	sc(n); sc(k);
	for(int j=0;j<2;j++) for(int i=1;i<=n;i++) sc(a[i][j]);
	int p1=0,p2=0,flg1=1,flg2=1,flg3=1,flg4=1;
	for(int i=1;i<=n;i++){
		if(!st[i-1] && i>1){
			if(a[i][0]>a[i][1]) p1=1,p2=1;
			else p1=0,p2=1;
		}else p1=(st[i-1]>=0),p2=abs(st[i-1]);
		
		printf("i:%d,st:%d,p1:%d,p2:%d,a0:%d,a1:%d\n",
				i,st[i-1],p1,p2,a[i][0],a[i][1]);
		if(a[i][0]>a[i][1]){
			if(!p1) a[i][0] += p2;
			if(a[i][0]>1LL*a[i][1]*k){
				st[i]=-(a[i][0]-a[i][1]*k);
				if(st[i]<-k){
					flg1=0;
					break;
				}
			}else st[i]=0;
		}else{
			if(p1) a[i][1] += p2;
			if(a[i][1]>1LL*a[i][0]*k){
				st[i]=a[i][1]-a[i][0]*k;
				if(st[i]>k){
					flg1=0;
					break;
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		if(!st[i-1] && i>1){
			if(a[i][0]>=a[i][1]) p1=1,p2=1;
			else p1=0,p2=1;
		}else p1=(st[i-1]>=0),p2=abs(st[i-1]);

		if(a[i][0]>=a[i][1]){
			if(!p1) a[i][0] += p2;
			if(a[i][0]>1LL*a[i][1]*k){
				st[i]=-(a[i][0]-a[i][1]*k);
				if(st[i]<-k) flg2=0;
			}else st[i]=0;
		}else{
			if(p1) a[i][1] += p2;
			if(a[i][1]>1LL*a[i][0]*k){
				st[i]=a[i][1]-a[i][0]*k;
				if(st[i]>k) flg2=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!st[i-1] && i>1){
			if(a[i][0]>a[i][1]) p1=1,p2=1;
			else p1=0,p2=1;
		}else p1=(st[i-1]>=0),p2=abs(st[i-1]);

		if(a[i][0]>=a[i][1]){
			if(!p1) a[i][0] += p2;
			if(a[i][0]>1LL*a[i][1]*k){
				st[i]=-(a[i][0]-a[i][1]*k);
				if(st[i]<-k) flg3=0;
			}else st[i]=0;
		}else{
			if(p1) a[i][1] += p2;
			if(a[i][1]>1LL*a[i][0]*k){
				st[i]=a[i][1]-a[i][0]*k;
				if(st[i]>k) flg3=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!st[i-1] && i>1){
			if(a[i][0]>=a[i][1]) p1=1,p2=1;
			else p1=0,p2=1;
		}else p1=(st[i-1]>=0),p2=abs(st[i-1]);

		if(a[i][0]>a[i][1]){
			if(!p1) a[i][0] += p2;
			if(a[i][0]>1LL*a[i][1]*k){
				st[i]=-(a[i][0]-a[i][1]*k);
				if(st[i]<-k) flg4=0;
			}else st[i]=0;
		}else{
			if(p1) a[i][1] += p2;
			if(a[i][1]>1LL*a[i][0]*k){
				st[i]=a[i][1]-a[i][0]*k;
				if(st[i]>k) flg4=0;
			}
		}
	}*/
	//if(flg1||flg2||flg3||flg4) puts("YES");
	if(flg1) puts("YES");
	else puts("NO");
	return 0;
}
