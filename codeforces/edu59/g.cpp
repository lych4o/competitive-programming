#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 3e5+10;
int n, a, D[maxn], c[maxn], h[maxn];
LL s[maxn], mx[maxn][20], mn[maxn][20];
pii d[maxn];
set<int> st;
void rmq_init(){
    for(int i=1,j=0;i<=n;h[i++]=j) while((1<<(j+1))<=i) j++;
    for(int i=0;i<=n;i++) mx[i][0]=mn[i][0]=s[i];
    for(int t=1;(1<<t)<=(n+1);t++){
        for(int l=0,r=l+(1<<(t-1));l+(1<<t)-1<=n;l++,r++){
            mx[l][t]=max(mx[l][t-1],mx[r][t-1]);
            mn[l][t]=min(mn[l][t-1],mn[r][t-1]);
        }
    }
}
LL qmax(LL l, LL r){
    if(l>r) return 0;
    int t = h[r-l];
    return max(mx[l][t],mx[r-(1<<t)+1][t]);
}
LL qmin(LL l, LL r){
    if(l>r) return 0;
    int t = h[r-l];
    return min(mn[l][t],mn[r-(1<<t)+1][t]);
}
int main(){
    LL ans = 0;
    sc(n); sc(a); st.insert(0); st.insert(n+1);
    for(int i=1;i<=n;i++) sc(D[i]), sc(c[i]), st.insert(i), c[i]=a-c[i], ans=max(1LL*c[i],ans);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
    for(int i=2;i<=n;i++) d[i].F = D[i]-D[i-1], d[i].S = i;
    rmq_init();
    sort(d+2,d+1+n);
    for(int i=2,j=2;i<=n;i++){
        while(d[j].F==d[i].F && j <=n) st.erase(d[j++].S);
        int l = *(--st.lower_bound(d[i].S)),
            r = *(st.lower_bound(d[i].S));
        LL tmp = qmax(d[i].S, r-1)-qmin(l-1,d[i].S)-1LL*d[i].F*d[i].F;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
