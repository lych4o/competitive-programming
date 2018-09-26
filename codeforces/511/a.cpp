#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int maxn = 3e5+10;
int gcd(int a, int b){
    if(!a) return b;
    return gcd(b%a, a);
}
int a[maxn], n;
vector<int> p;
int vis[maxn];
void init(){
    for(int i = 2; i*i < 1.5e7; i++){
        if(vis[i]) continue;
        p.pb(i);
        for(int j = 2*i; j < maxn; j += i){
            vis[j] = 1;
        }
    }
}
vector<int> v;
int main(){
    init();
    //cout << p.size() << endl;
    sc(n);
    int g = 0;
    for(int i = 0; i < n; i++){
        sc(a[i]);
        g = gcd(g,a[i]);
    }
    for(int i = 0; i < n; i++){
        a[i] /= g;
        int tmp = a[i];
        //printf("a[%d]:%d\n",i,a[i]);
        for(int j = 0; p[j]*p[j]<=tmp && j < (int)p.size(); j++){
            if(tmp%p[j]) continue;
            while((tmp%p[j])==0) tmp /= p[j];
            v.pb(p[j]);
            //printf("a[%d]:%d, p:%d\n",i,a[i],p[j]);
        }
        if(tmp > 1) v.pb(tmp);
    }
    //for(int a: v) printf("%d ", a); puts("");
    sort(v.begin(),v.end());
    int ans = n;
    for(int i = 0, j = 0; i < (int)v.size(); i = j){
        while(v[j]==v[i] && j <(int)v.size()) j++;
        ans = min(ans, n-j+i);
    }
    if(ans==n) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
