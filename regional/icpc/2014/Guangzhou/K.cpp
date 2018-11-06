#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld", &x)
#define pb push_back
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
//const LL mod = 1e9+7;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 40;

int n, m;
LL d[maxn][maxn], dd[maxn][maxn];

void floyd(){
    for(int i=1;i<=n;i++) dd[i][i]=0;
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        if(dd[i][j]>dd[i][k]+dd[k][j])
            dd[i][j]=dd[i][k]+dd[k][j];
    }
    /*for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            printf("d[%d][%d]:%lld\n",i,j,dd[i][j]);
        }
    }*/
}

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        if(!n&&!m) break;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            d[i][j]=INF;
        for(int i = 0; i < m; i++){
            int u, v; LL w; sc(u); sc(v); sll(w);
            d[u][v]=min(d[u][v],w);
            d[v][u]=min(d[v][u],w);
            //printf("d[%d][%d]:%lld\n",u,v,d[u][v]);
        }
        LL ans = 0;
        for(int i = 2; i < n; i++){
            memcpy(dd, d, sizeof(d));
            for(int j = 1; j <= n; j++) dd[i][j]=dd[j][i]=INF;
            //for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
              //  printf("dd[%d][%d]:%lld\n",i,j,dd[i][j]);
            floyd();
            ans = max(ans, dd[1][n]);
        }
        if(ans==INF){
            printf("Inf\n");
        }else printf("%lld\n",ans);
    }
    return 0;
}
