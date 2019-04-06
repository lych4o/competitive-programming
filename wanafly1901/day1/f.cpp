#include<bits/stdc++.h>
/*
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
*/
#define sll(x) scanf("%lld", &x)
#define sc(x) scanf("%d",&x)
#define mk make_pair
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
typedef pair<LL,LL> pLL;
struct E{
    int u, v;
    LL w;
    E(int u=0, int v=0, LL w=0):u(u),v(v),w(w){}
    bool operator < (const E& rr) const{
        return w > rr.w;
    }
};
vector<E> to[maxn];
int n, m, k, h[maxn];
LL cost[maxn];

LL dijkstra(){
    for(int i=2;i<=n;i++) cost[i] = 2e15+10;
    priority_queue<pLL, vector<pLL>, greater<pLL> > q;
    q.push(mk(0,1));
    while(q.size()){
        pLL p = q.top(); q.pop();
        if(cost[p.S] < p.F) continue;
        for(E e: to[p.S]){
            if(cost[e.v] > cost[p.S] + e.w){
                cost[e.v] = cost[p.S] + e.w;
                q.push(mk(cost[e.v], e.v));
            }
        }
    }
    return cost[n];
}
int main(){
    sc(n); sc(m); sc(k);
    for(int i=1;i<=n;i++) sc(h[i]);
    for(int i=0;i<m;i++){
        int u, v, w; sc(u); sc(v); sc(w);
        int dv = max(0, h[v]-h[1]-k),
            du = max(0, h[u]-h[1]-k);
        to[u].pb(E(u,v,w+1LL*dv*dv));       
        to[v].pb(E(v,u,w+1LL*du*du));
    }
    printf("%lld\n", dijkstra());
    return 0;
}
