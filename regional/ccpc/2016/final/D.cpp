#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 1e5+10;
int n, m, R, num[maxn], r, mn[maxn];
int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); sc(m); sc(R);
        priority_queue<pii> q;
        for(int i=1;i<=n;i++){
            sc(num[i]);
            mn[i]=min(i,R);
        }
        for(int i=0;i<m;i++){
            int u, v; sc(u); sc(v);
            if(u>v) swap(u,v);
            mn[v]=min(mn[v],u);
        }
        mn[R] = 1;
        for(int i=1;i<=n;i++) q.push(mk(-mn[i],i));
        LL ans=0;
        for(int i=1;i<=n;i++){
            while(num[i]>0 && q.size()){
                pii now = q.top(); q.pop();
                //printf("i:%d, (%d:%d)\n",i,now.S,-now.F);
                if(-now.F < i) continue;
                if(-now.F >= i) num[i]--;
            }
            ans += num[i];
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
