#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
int n, a[maxn];

int main(){
    sc(n); LL sum = 0;
    for(int i = 1; i <= n; i++) sc(a[i]), sum+=a[i];   
    sort(a+1,a+1+n);
    sum -= a[1]; sum += (n-1)*1LL*a[1];
    cout << sum << endl;
    return 0;
}
