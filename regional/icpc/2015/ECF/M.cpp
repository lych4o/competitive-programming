#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
const int maxn = 1e3+10;
int mx[maxn], mn[maxn];

int n, m, b, vis[maxn][maxn];
int main(){
    int T; sc(T);
    for(int kase=1; kase<=T; kase++){
        sc(n); sc(m); sc(b);
        memset(vis,0,sizeof(vis));
        for(int i=0; i<b; i++){
            int r,c; sc(r); sc(c);
            vis[r+1][c+1]=1;
        }
        int ans0=0, ans1=0;
        for(int i=1; i<=n;i++){
            for(int l=1,r;l<=m;l=r+1){
                r = l;
                while(r<=m && !vis[i][r]) r++;
                if(vis[i][l]) continue;
                ans1 += (r-l+2)/3;
                ans0 += (r-l+1)/2;
            }
        }
        printf("Case #%d: %d %d\n", kase,ans0,ans1);
    }
    return 0;
}
