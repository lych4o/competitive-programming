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

int n, m, a[maxn], b[maxn];
int main(){
    sc(n);
    int ans=1, px=0, py=0;
    for(int i=0;i<n;i++){
        sc(a[i]),sc(b[i]);
        if(px==py) ans += max(min(a[i],b[i])-max(px,py), 0);
        else ans += max(min(a[i],b[i])-max(px,py)+1, 0);
        px = a[i], py = b[i];
    }
    cout << ans << endl;
    return 0;
}
