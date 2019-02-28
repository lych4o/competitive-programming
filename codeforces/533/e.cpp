#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
map<string, int> mp;
const int maxn = 45;
vector<LL> v;
int n, m, dp[1<<20];
LL b[maxn];
inline int ID(string& s){
    if(mp.count(s)==0){
        int x = mp.size();
        mp[s] = x;
    }
    return mp[s];
}

int solve(LL x){
    int ret = (x<(1<<20))?dp[x]:0;
    if(!ret && x>0){
        for(int i=m-1;i>=0;i--){
            if((x>>i)&1){
                ret = max(solve(x^(1LL<<i)), solve(x&b[i])+1);
                break;
            }
        }
    }
    if(x<(1<<20)) dp[x] = ret;
    return ret;
}
int main(){
    sc(n); sc(m);
    for(int i=0;i<n;i++){
        int op; sc(op);
        if(op==1){
            v.push_back(0);
        }else{
            string str; cin >> str;
            int id = ID(str);
            v.back() |= (1LL<<id);
        }
    }
    for(LL x: v){
        for(int i=0;i<m;i++) for(int j=0;j<m;j++){
            if(((x>>i)&1) && ((x>>j)&1)) b[i] |= (1LL<<j), b[j] |= (1LL<<i);
        }
    }  
    for(int i=0;i<m;i++) b[i] = ~b[i];
    printf("%d\n", solve((1LL<<m)-1));
    return 0;
}
