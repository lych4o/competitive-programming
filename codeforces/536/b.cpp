#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 1e5+10;
int a[maxn], c[maxn], d[maxn], t[maxn], n, m;
set<pii> st;

LL serve(int type, int num){
    //printf("serve(%d,%d)\n",type,num);
    if(num == 0) return 0;
    if(a[type] > num){
        a[type] -= num;
        return 1LL*c[type]*num;
    }
    int cnt = a[type];
    a[type] = 0; st.erase(mk(c[type],type));
    if(!st.size() && num>cnt) return -1;
    LL nxt = serve((st.begin())->S, num-cnt);
    if(nxt<0) return -1;
    else return nxt+1LL*cnt*c[type];
}
int main(){
    sc(n); sc(m);
    for(int i=1;i<=n;i++) sc(a[i]);
    for(int i=1;i<=n;i++) sc(c[i]), st.insert(mk(c[i],i));
    for(int i=0;i<m;i++){
        sc(t[i]); sc(d[i]);
        LL ret = max(serve(t[i],d[i]),0LL);
        printf("%lld\n", ret);   
    }
    return 0;
}
