#include<bits/stdc++.h>
#define debug puts("???")
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn = 1e6+10;

int n, m, x[maxn], y[maxn], pre[maxn], nxt[maxn],
    f[maxn], L[maxn], R[maxn];
int Find(int x){
    if(x==f[x]) return x;
    return f[x] = Find(f[x]);
}
int main(){
    sc(n);
    for(int i=1;i<=n;i++) f[i]=L[i]=R[i]=i;
    for(int i=1;i<n;i++){
        sc(x[i]), sc(y[i]);
        int fx=Find(x[i]), fy=Find(y[i]);
        f[fx] = fy;
        nxt[R[fx]] = L[fy];
        pre[L[fy]] = R[fx];
        L[fy] = L[fx];
        R[fy] = R[fy];
    }
    int bg;
    for(int i=1;i<=n;i++) if(pre[i]==0) bg=i;
    int u = bg;
    for(int i=0;i<n;i++){
        printf("%d%c",u,i==n-1?'\n':' ');
        u = nxt[u];
    }
    return 0;
}
