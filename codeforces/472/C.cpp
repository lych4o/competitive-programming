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
#define sll(x) scanf("%I64d", &x)
#define sz(x) int((x).size())
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 1e5+10;

int bit[maxn], a[maxn], mx[maxn], n;

int main(){
    sc(n);
    for(int i = 1; i <= n; i++) sc(a[i]);
    mx[n] = a[n]-(n-1); mx[n+1] = -maxn;
    for(int i = n-1; i >= 1; i--)
        mx[i] = max(mx[i+1],a[i]+1-i);
    int now = 0;
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        //printf("i:%d, now:%d, mx[%d]:%d\n",i,now,i+1,mx[i+1]);
        ans += now-a[i];
        if(now-i < mx[i+1] || a[i]==now) now++;
        else ans--;
    }
    printf("%I64d\n", ans);
    return 0;
}
