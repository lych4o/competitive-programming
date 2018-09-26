#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 25;
vector<int> v;
int a[maxn], vis[maxn], n, ans;

int check(){
    v.clear();
    for(int i=0; i<n; i++) if(!vis[i]) v.pb(a[i]);
    for(int i=2; i<(int)v.size(); i++){
        if(v[i] < v[i-1]+v[i-2]) return 1;
    }
    return 0;
}
void dfs(int p, int cnt){
    if(cnt > ans) return;
    if(p == n){
        /*printf("check(");
        for(int i = 0;i < n;i++) if(!vis[i]) printf("%d ",i+1);
        printf("):%d\n",check());*/
        if(check()==0) ans = min(cnt, ans);
        return ;
    }
    dfs(p+1,cnt); vis[p] = 1;
    dfs(p+1,cnt+1); vis[p] = 0;
}

int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); for(int i = 0; i < n; i++) a[i]=i+1;
        ans = maxn;
        dfs(0,0);
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
