#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define SZ(x) ((int)x.size())
#define F first
#define S second
#define sc(x) scanf("%d",&x)
using namespace std;
typedef double db;
typedef pair<double,int> pdi;
const db PI = acos(-1.0);
const db eps = 1e-6;
const int maxn = 1e5+10;
int dcmp(db x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct P{
	int x, y;
	db ang;
	P(int x=0,int y=0):x(x),y(y){}
	db Angle(){return atan2(y,x);}
	bool operator < (const P& rhs) const{
		return ang < rhs.ang;
	}
} p[maxn];
int n,xc,yc;
vector<pdi> v;
int main(){
	sc(n); sc(xc); sc(yc);
	n--;
	int cnt=0;
	for(int i=0;i<n;i++){
		sc(p[i].x); sc(p[i].y);
		p[i].x-=xc; p[i].y-=yc;
		if(p[i].x==0 && p[i].y==0){
			cnt++;
			continue;
		}
		p[i].ang = p[i].Angle()+PI;
		db l = p[i].ang-PI/2, r = p[i].ang+PI/2;
		if(l<0){
			l += 2*PI; r += 2*PI;
			v.pb(mk(l,1)); v.pb(mk(r,-1));
		}else{
			v.pb(mk(l,1)); v.pb(mk(r,-1));
			v.pb(mk(l+2*PI,1)); v.pb(mk(r+2*PI,-1));
		}
	}
	v.pb(mk(PI+PI/4,0));
	sort(v.begin(), v.end());
	int now=0,mx=0,mn=n;
	for(int i=0,j;i<SZ(v);i=j){
		j=i+1;
		int pos=v[i].S>0,neg=v[i].S<0;
		while(j<SZ(v) && dcmp(v[j].F-v[i].F)==0){
			pos+=v[j].S>0; neg+=v[j].S<0;
			j++;
		}
		if((v[i].F>=PI&&v[i].F<=PI+PI/2)||
		   (v[i].F>=3*PI&&v[i].F<=3*PI+PI/2)){
			mx=max(mx,now+pos);
			mn=min(mn,now-neg);
		}
		now=now+pos-neg;
	}
	printf("%d %d\n",mn+1,mx+1+cnt);
	return 0;
}
