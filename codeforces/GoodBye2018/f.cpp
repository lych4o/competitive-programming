#include<bits/stdc++.h>
#define sz(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
typedef double db;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n, l[maxn], tp[maxn];
char str[maxn];
LL upd(LL& x, LL& y){
	y *= 2;
	LL mn=min(x,y);
	x -= mn; y -= mn;
	y /= 2;
	return mn;
}
int main(){
	sc(n);
	for(int i=1;i<=n;i++) sc(l[i]), l[i]*=2;
	scanf("%s", str);
	for(int i=1;i<=n;i++){
		if(str[i-1]=='G') tp[i] = 0;
		if(str[i-1]=='W') tp[i] = 1;
		if(str[i-1]=='L') tp[i] = 2;
	}
	LL ww=0,c1=0,c2=0;
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(tp[i]==0){
			LL tmp = l[i], mn;
			//printf("0:c1:%lld, c2:%lld, tmp:%lld, ans:%lld\n",c1,c2,tmp,ans);
			mn = upd(tmp, c2); ans+=2*mn; c1 += mn;
			ans += tmp*(1+5)/2; c1 += tmp/2;
		}else if(tp[i]==1){
			ww=1;
			LL tmp = l[i], mn;
			//printf("1:c1:%lld, c2:%lld, tmp:%lld, ans:%lld\n",c1,c2,tmp,ans);
			ans += tmp*(1+3)/2; c2 += tmp/2;
		}else{
			LL tmp = l[i], mn;
			//printf("2:c1:%lld, c2:%lld, tmp:%lld, ans:%lld\n",c1,c2,tmp,ans);
			mn = upd(tmp, c2); ans+=2*mn;
			//printf("2:c1:%lld, c2:%lld, tmp:%lld, ans:%lld\n",c1,c2,tmp,ans);
			mn = upd(tmp, c1); ans+=3*mn;
			//printf("2:c1:%lld, c2:%lld, tmp:%lld, ans:%lld\n",c1,c2,tmp,ans);
			if(tmp>0){
				if(ww==1) ans += tmp*(3+1);
				else ans += tmp*(5+1);
			}
		}
	}
	cout << ans/2 << endl;
	return 0;
}
