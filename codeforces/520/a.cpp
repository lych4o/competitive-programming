#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef double db;
typedef long long LL;
const int maxn = 1e6+10;
LL n, a[maxn];
int main(){
    sll(n);
    for(int i=1;i<=n;i++) sll(a[i]);
    a[n+1]=100000;
    int mx = 0;
    for(int i=1,j;i<=n;i=j){
        j=i+1;
        while(j<=n && a[j]==a[j-1]+1) j++;
        int len=j-i-2;
        if(a[i]==1||a[j-1]==1000) len++;
        mx = max(mx, len);
    }
    cout << mx << endl;
    return 0;
}
