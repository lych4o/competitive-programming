#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
const int maxn = 1e3+10, maxk = 1e5+10;
int n, a[maxn], vis[maxk];
int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        memset(vis,0,sizeof(vis));
        sc(n);
        int ans = 0;
        for(int i=1;i<=n;i++) sc(a[i]);
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                //printf("l:%d, r:%d\n",l,r);
                if(vis[a[r]]) break;
                vis[a[r]]=1;
                ans=max(ans,r-l+1);
                for(int p=r+1,q=r+1;p<=n;p++){
                    while(q<p) q++;
                    while(q<=n && !vis[a[q]]){
                        vis[a[q]]=1;
                        q++;
                    }
                    //printf("[%d-%d],[%d,%d):%d\n",
                      //      l,r,p,q,q-p+r-l+1);
                    ans = max(ans, q-p+r-l+1);
                    if(q>p) vis[a[p]]=0;
                }
            }
            for(int i=l;i<=n;i++) vis[a[i]]=0;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
