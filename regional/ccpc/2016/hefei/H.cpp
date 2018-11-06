#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
const int maxn = 105, maxv = 1100;
int mx[1100], a[maxn], n, m, xsum[maxn];
int main(){
    int T; sc(T);
    while(T--){
        sc(n); for(int i=1;i<=n;i++) sc(a[i]);
        for(int i=1;i<=n;i++) xsum[i]=xsum[i-1]^a[i];
        memset(mx,0,sizeof(mx));
        for(int l=0;l<n;l++) for(int r=1;r<=n;r++){
            int tmp=xsum[r]^xsum[l];
            mx[tmp]=max(mx[tmp],r-l);
        }
        sc(m);
        while(m--){
            int x; sc(x);
            int ans=0;
            for(int i=0;i<maxv;i++){
                if(ans>0) break;
                if(x-i>=0) ans=max(ans,mx[x-i]);
                if(x+i<maxv) ans=max(ans,mx[x+i]);
            }
            printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}
