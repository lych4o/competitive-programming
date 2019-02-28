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

char s[maxn], msc[]="msc", mcc[]="mcc";
int ns[maxn], nm[maxn], nc[maxn], n, vis[maxn];
vector<int> vp;
vector<string> vs;
void dfs(int p1, int p2, string s){
    if(p1==3&&p2==3){
        vs.pb(s);
        return;
    }
    if(p1<3) dfs(p1+1,p2,s+msc[p1]);
    if(p2<3) dfs(p1,p2+1,s+mcc[p2]);
}
inline int nxt(char s, int p){
    if(s=='m') return nm[p];
    if(s=='s') return ns[p];
    if(s=='c') return nc[p];
    return n;
}
int get(int x){
    int ret=n;
    for(string s: vs){
        //cout << "solve("<<s<<"):";
        int p=x;
        for(int i=0;i<SZ(s);i++){
            //cout << p << "->";
            if(p>=n) break;
            p = nxt(s[i],p);
            if(i<SZ(s)-1) p++;
        }
        //puts("");
        ret = min(ret, p);
    }
    return ret;
}
int main(){
    sc(n);
    scanf("%s", s);
    n = strlen(s);
    int rs=n,rm=n,rc=n;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='s') rs=i;
        if(s[i]=='c') rc=i;
        if(s[i]=='m') rm=i;
        ns[i]=rs; nm[i]=rm; nc[i]=rc;
    }
    dfs(0,0,"");
    LL ans=0;
    for(int i=0;i<n;i++){
        int nn=get(i);
       // printf("i:%d, nn:%d\n",i,nn);
        ans += n-nn;
    }
    cout << ans << endl;
    return 0;
}
