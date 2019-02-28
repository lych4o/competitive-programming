#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e5+10, maxk = 105;
const int mod = 998244353;
int dp[maxn][maxk], n, len, k, a[maxn], mx[maxk], sum[maxn];
void add(int& x, int y){x=(x+y)>=mod?x+y-mod:x+y;}
int main(){
    sc(n); sc(k); sc(len);
    if(len==1) return puts("0"), 0;
    dp[0][0]=sum[0]=1;
    for(int i=1;i<=k;i++) sum[1]+=dp[1][i];
    for(int i=1;i<=n;i++){
        //for(int j=1;j<=k;j++) printf("mx[%d]:%d\n",j,mx[j]);
        sc(a[i]);
        if(a[i]<0){
            for(int j=1;j<=k;j++){
                add(dp[i][j],sum[i-1]);
                if(mx[j]>=len-1){
                    add(dp[i][j],dp[i-len][j]);
                    add(dp[i][j],mod-sum[i-len]);
                }
                add(sum[i],dp[i][j]);
                mx[j]++;
            }
        }else{
            add(dp[i][a[i]],sum[i-1]);
            if(mx[a[i]]>=len-1){
                add(dp[i][a[i]],dp[i-len][a[i]]);
                add(dp[i][a[i]],mod-sum[i-len]);
            }
            mx[a[i]]++; sum[i]=dp[i][a[i]];
            for(int j=1;j<=k;j++) if(j!=a[i]) mx[j]=0;
        }
        //for(int j=1;j<=k;j++) printf("dp[%d][%d]:%d\n",i,j,dp[i][j]);
        //printf("sum[%d]:%d\n",i,sum[i]);
    }
    printf("%d\n", sum[n]);
    return 0;
}
