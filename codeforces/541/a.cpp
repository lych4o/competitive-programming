#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn = 1e6+10;

LL w1,h1,w2,h2;
int main(){
    cin >> w1>>h1>>w2>>h2;
    LL ans = w1+1+h1+h2+1+w2+h2+2+abs(w1-w2)+h1;
    cout << ans << endl;
    return 0;
}
