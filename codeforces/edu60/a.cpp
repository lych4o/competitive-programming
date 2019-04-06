#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const int maxn = 1e6+10;

int a[maxn], n;

int main(){
    int mx = 0, ans = 1;
    sc(n); for(int i=0;i<n;i++) sc(a[i]), mx = max(mx, a[i]);
    for(int i=0,j;i<n;i=j){
        for(j=i;j<n && a[j]==a[i];j++);
        if(a[i]==mx) ans = max(ans, j-i);
    }
    cout << ans << endl;
    return 0;
}
