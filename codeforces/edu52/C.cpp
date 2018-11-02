#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define ln puts("")
#define sp putchar(' ')
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fout fflush(stdout)
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
//const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n, k, h[maxn], mx, mn;
LL sum[maxn], cnt[maxn];

int main(){
    sc(n); sc(k);
    mn = maxn;
    for(int i = 1; i <= n; i++) 
        sc(h[i]), cnt[h[i]+1]--, 
            mx=max(mx,h[i]),mn=min(mn,h[i]);
    int now = n;
    for(int i = 0; i <= mx; i++){
        now += cnt[i];
        sum[i] += now;
        //printf("sum[%d]:%lld\n",i,sum[i]);
    }
    for(int i = 1; i <= mx; i++){
        sum[i] += sum[i-1];
        cnt[i] += cnt[i-1];
        //printf("sum[%d]:%lld\n",i,sum[i]);
    }
    int pre = mx, ans = 0;
    for(int h = mx; h >= 1; h--){
        //printf("pre:%d, h:%d, sum:%lld, %lld\n",
          //      pre,h,sum[pre], sum[h-1]);
        //printf("cnt[%d]:%lld, sum:%lld\n",
          //      h,cnt[h],sum[pre]-sum[h-1]);
        if(sum[pre]-sum[h-1] > k || cnt[h]==0){
            //printf("h:%d\n",h);
            ans++;
            pre = h;
        }
        if(cnt[h]==0) break;
    }
    if(mn==mx) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}
