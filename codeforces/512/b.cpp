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
#define sz(x) int((x).size())
#define sll(x) scanf("%I64d", &x)
#define pr(x) printf("%d",x)
#define sp putchar(' ');
#define ln puts("")
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9+7;
const int maxn = 3e5+10;

LL a[maxn],cnt[maxn],sum[maxn],suf[maxn][2];
int n;

int main(){
    sc(n);
    for(int i = 1; i <= n; i++){
        sll(a[i]); LL tmp = a[i];
        while(tmp > 0){
            cnt[i]++;
            tmp -= tmp&-tmp;
        }
        sum[i] = sum[i-1]+cnt[i];
    }
    for(int i = n; i >= 1; i--){
        suf[i][0]=suf[i+1][0]; suf[i][1]=suf[i+1][1];
        suf[i][sum[i]%2]++;
    }
    LL ans = 0;
    for(int l = 1, r; l <= n; l++){
        LL mx = 0, all;
        for(r = l; r-l+1 <= 70 && r <= n; r++){
            all = sum[r]-sum[l-1];
            mx = max(mx, cnt[r]);
            if(all-mx*2 < 0 || all%2) continue;
            ans++;
        }
        ans += suf[r][sum[l-1]%2];
    }
    cout << ans << endl;
    return 0;
}
