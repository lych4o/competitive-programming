#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
using namespace std;
typedef long long LL;
const LL mod = 1e8+7;
const int maxn = 1e4+10;
LL dp[maxn][1<<4];
vector<int> to[10][(1<<4)];
int n, v[maxn], cnt[(1<<4)];
char s[maxn];

int main(){
    int T; sc(T);
    for(int i=0;i<(1<<4);i++) for(int j=0;j<4;j++)
        if((i>>j)&1) cnt[i]++;
    for(int i=0;i<10;i++) for(int j=0;j<(1<<4);j++){
        int cj=cnt[j];
        if(cj>i) continue;
        for(int k=0;k<(1<<2);k++){
            int ck=cnt[k];
            if(ck+cj != i) continue;
            to[i][j].pb(k);
        }
    }
    while(T--){
        scanf("%s", s); n=strlen(s);
        int flg=0;
        for(int i=0;i<n;i++){
            v[i+1]=s[i]-'0';
            if(v[i+1]>6) flg=1;
        }
        if(flg){
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<(1<<2);i++){
            int tmp = i<<2;
            if(cnt[tmp]>v[1]) continue;
            dp[1][tmp]++;
        }
        for(int i=1;i<n;i++)for(int j=0;j<(1<<4);j++){
            for(int k: to[v[i]][j]){
                int nxt=(j>>2)|(k<<2);
                //printf("dp[%d][%d]-->dp[%d][%d]\n",i,j,i+1,nxt);
                dp[i+1][nxt] += dp[i][j];
                dp[i+1][nxt] %= mod;
            }
        }
        LL ans=0;
        for(int i=0;i<(1<<4);i++){
            if(cnt[i]==v[n]) ans=(ans+dp[n][i])%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}//
