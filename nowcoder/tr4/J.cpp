#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;

string pre, s;
int n, m, x, xx;
set<int> st, sst;
vector<int> ans;

int main(){
    sc(n); sc(m); cin >> xx >> pre;
    sst.insert(xx);
    for(int i=1; i<=n;i++) st.insert(i);
    for(int i = 1; i < m; i++){
        cin >> x >> s;
        if(s==pre) st.insert(x);
        else pre = s, sst.insert(x);
    }
    for(int x: sst) st.erase(x);
    for(int x: st) ans.push_back(x);
    //sort(ans.begin(),ans.end());
    for(int i=0;i<(int)ans.size();i++)
        printf("%d%c",ans[i]," \n"[i==(int)ans.size()-1]);
    return 0;
}
