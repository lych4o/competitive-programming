#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define mk make_pair
using namespace std;
typedef pair<int,int> pii;

pii p[3];
int check(){
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++) if(i!=j)
	for(int k=0;k<3;k++) if(k!=j&&k!=i){
		if(p[k].F>=p[i].F&&p[k].F<=p[j].F&&
		   p[k].S>=p[i].S&&p[k].S<=p[j].S)
			return k;
	}
	return -1;
}
vector<pii> ans;
inline int dis(pii a, pii b){
	return abs(a.F-b.F)+abs(a.S-b.S);
}
int get_dis(pii x){
	int ret=0;
	for(int	i=0;i<3;i++){
		ret += dis(x,p[i]);
	}
	return ret;
}
void get_ans(pii u){
	//printf("get_ans(%d,%d)\n",u.F,u.S);
	ans.pb(u);
	for(int i=0;i<3;i++){
		int x=u.F,y=u.S,
			dx=(x>p[i].F)?-1:1,
			dy=(y>p[i].S)?-1:1;
		while(x!=p[i].F) x+=dx, ans.pb(mk(x,y));
		while(y!=p[i].S) y+=dy, ans.pb(mk(x,y));
	}
}
int main(){
	for(int i=0;i<3;i++) cin >> p[i].F >> p[i].S;
	if(check()>=0){
		get_ans(p[check()]);
	}else{
		pii pp; 
		int mn = 1e6+10;
		for(int x=0;x<=1000;x++) for(int y=0;y<=1000;y++){
			pii tmp = mk(x,y);
			if(get_dis(tmp)<mn){
				//printf("dis(%d,%d):%d\n",x,y,get_dis(tmp));
				pp = mk(x,y), mn=get_dis(tmp);
			}
		}
		get_ans(pp);
	}
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].F,ans[i].S);
	}
	return 0;
}
