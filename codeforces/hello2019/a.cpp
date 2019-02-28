#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxn = 1e6+10;
string s, t;

int main(){
    cin >> t;
    for(int i=0;i<5;i++){
        cin >> s;
        if(s[0]==t[0] || s[1]==t[1]){
            cout << "YES"<<endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
