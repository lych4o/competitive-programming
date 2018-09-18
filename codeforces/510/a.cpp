#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#define pii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define debug puts("???");
#define br puts("")
#define ALL(x) x.begin(),x.end()
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 2e5+10;

int n, a[maxn], m;
int main(){
    cin >> n >> m;
    int mm = m;
    int mx = 0;
    for(int i = 0; i < n; i++){
        sc(a[i]);
        mx = max(mx, a[i]);
    }
    sort(a, a+n);
    for(int i = 0; i < n-1; i++){
        m -= mx-a[i];
        if(m <= 0) break;
    }
    if(m <= 0) printf("%d %d\n", mx, mx+mm);
    else{
        printf("%d %d\n", mx+(m+n-1)/n, mx+mm);
    }
    return 0;
}
