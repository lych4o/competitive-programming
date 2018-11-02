#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define mk make_pair
#define fi first
#define se second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
//const int maxn = 1e6+10;

int n;
vector<int> p0,p1,p2;
string s;
int main(){
    int T; sc(T);
    while(T--){
        cin >> s;
        p0.clear(); p1.clear(); p2.clear();
        for(int i = 0; i < SZ(s); i++){
            if(s[i]>='a'&&s[i]<='z') p0.pb(i);
            else if(s[i]>='A'&&s[i]<='Z') p1.pb(i);
            else p2.pb(i);
        }
        //printf("%d,%d,%d\n",SZ(p0),SZ(p1),SZ(p2));
        if(SZ(p0)==0){
            if(SZ(p1)>1) s[p1.back()]='a', p1.pop_back();
            else s[p2.back()]='a', p2.pop_back();
        }
        if(SZ(p1)==0){
            if(SZ(p0)>1) s[p0.back()]='A', p0.pop_back();
            else s[p2.back()]='A', p2.pop_back();
        }
        if(SZ(p2)==0){
            if(SZ(p0)>1) s[p0.back()]='1',p0.pop_back();
            else s[p1.back()]='1',p1.pop_back();
        }
        cout << s << endl;
    }
    return 0;
}
