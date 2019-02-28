#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn = 405;

int dp[maxn][maxn][maxn], n, m, a[maxn];
int main(){
    sc(n); sc(m);
    for(int i=0;i<n;i++) sc(a[i]);
    for(int L=0;L<n;L++){
        for(int R = L; R < n; R++) dp[L][R][0] = a[R]-a[L];
        for(int i = 1; i <=n; i++){
            int j = L;
            for(int R = L; R < n; R++){
                while(j<R && max(dp[L][j][i-1],a[R]-a[j])>max(dp[L][j+1][i-1],a[R]-a[j+1])) 
                    j++;
                dp[L][R][i] = max(dp[L][j][i-1],a[R]-a[j]);
                //printf("dp[%d][%d][%d]:max(%lld, %lld)\n",L,R,i,dp[L][j][i-1],1LL*a[R]-a[j]);
            }
        }
    }
    LL ans = 0;
    while(m--){
        int s, f, c, r; sc(s); sc(f); sc(c); sc(r);
        s--; f--;
        ans = max(ans, 1LL*dp[s][f][r]*c);
        //printf("dp[%d][%d][%d]*%d:%lld\n",s,f,r,c,c*dp[s][f][r]);
    }
    cout << ans << endl;
    return 0;
}
