#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 1e5+10;

char s[maxn];
int ns[maxn], nm[maxn], nc[maxn], n, vis[maxn];
vector<int> vp;
int msc(int p){
    while(p<n && vis[p]) p=nm[p]; vis[p]=1; vp.pb(p);
    while(p<n && vis[p]) p=ns[p]; vis[p]=1; vp.pb(p);
    while(p<n && vis[p]) p=nc[p]; vis[p]=1; vp.pb(p);
    return p;
}
int mcc(int p){
    while(p<n && vis[p]) p=nm[p]; vis[p]=1; vp.pb(p);
    while(p<n && vis[p]) p=nc[p]; vis[p]=1; vp.pb(p);
    while(p<n && vis[p]) p=nc[p]; vis[p]=1; vp.pb(p);
    return p;
}
int main(){
    sc(n);
    scanf("%s", s);
    n = strlen(s);
    int rs=n,rm=n,rc=n;
    for(int i=n-1;i>=0;i--){
        ns[i]=rs; nm[i]=rm; nc[i]=rc;
        if(s[i]=='s') rs=i;
        if(s[i]=='c') rc=i;
        if(s[i]=='m') rm=i;
    }
    LL ans=0;
    for(int i=0;i<n;i++){
        int mn = n, p1, p2;
        p1=msc(i); p2=mcc(i);
        mn = min(mn, max(p1,p2));
        for(int p: vp) vis[p]=0;
        p1=mcc(i); p2=msc(i);
        mn = min(mn, max(p1,p2));
        for(int p: vp) vis[p]=0;
        printf("i:%d, mn:%d\n",i,mn);
        ans += n-mn;
    }
    cout << ans << endl;
    return 0;
}
