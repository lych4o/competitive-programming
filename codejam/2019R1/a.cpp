#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typdef pair<int,int> pii;
vector<pii> ans;
int n, m;
int main(){
	int T; cin >> T;
	for(int kase=1;kase<=T;kase++){
		ans.clear();
		cin >> n >> m;
		int flg = 1, swp = 0;
		if(n>m) swap(n,m), swp = 1;
		if(n<=3 && m<=3) flg = 0;
		if(n==1) flg = 0;
		if(n==2 && m==4) flg = 0;
		if(n==3 && m==4){
			/*
			ans.pb(mk(2,3)); ans.pb(mk(1,1)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
			ans.pb(mk(3,1)); ans.pb(mk(1,3)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
			ans.pb(mk(2,3)); ans.pb(mk(1,1)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
			*/
			flg = 0;
		}
		if(n==4 && m==4){
			ans.pb(mk(3,1)); ans.pb(mk(2,3)); ans.pb(mk(4,1)); ans.pb(mk(3,3));
			ans.pb(mk(2,3)); ans.pb(mk(1,1)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
			ans.pb(mk(2,3)); ans.pb(mk(1,1)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
			ans.pb(mk(2,3)); ans.pb(mk(1,1)); ans.pb(mk(2,4)); ans.pb(mk(1,2));
		}

	}
	return 0;
}
