#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
typedef long long LL;
//typedef pair<int,int> pii;
//typedef pair<LL,LL> pLL;
using namespace std;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    LL ans = 0;
    for(int i=0; i<s.size();i++){
        if((s[i]-'0')%2) continue;
        ans += i+1;
    }
    cout << ans << endl;
    return 0;
}
