#include<iostream>
#include<cstdio>
using namespace std;
//const int maxn = 1e3+10;
typedef long long LL;

LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL a, b, x, y;
int main(){
    cin >> a >> b >> x >> y;
    LL g = gcd(x,y);
    x /= g; y /= g;
    cout << min(a/x,b/y) << endl;
    return 0;
}
