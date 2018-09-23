#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#define pii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define debug puts("???");
#define br puts("")
#define ALL(x) x.begin(),x.end()
#define sc(x) scanf("%d", &x)
#define sz(x) int((x).size())
#define pr(x) printf("%d",x)
#define sp putchar(' ');
#define ln puts("")
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

LL gcd(LL a, LL b){
    if(!a) return b;
    return gcd(b%a, a);
}
LL n, m, k, ar;
vector<int> p,p1;

int flg;
void dfs(int i, LL now){
    //printf("dfs(%d,%I64d), %lld, %lld\n",i,now,ar,ar/now);
    if(flg==1) return;
    if(now <= n && (ar/now) <= m){
        printf("YES\n0 0\n%I64d 0\n0 %I64d\n",now,ar/now);
        flg = 1;
        return;
    }
    if(i >= (int)p1.size()) return;
    dfs(i+1,now);
    while(((ar/now)%p1[i])==0){
        now *= p1[i];
        dfs(i+1, now);
    }
}

int main(){
    cin >> n >> m >> k;
    ar = n*m*2;
    //printf("%lld, %lld\n",ar,k);
    if((ar%k)>0) return puts("NO"), 0;
    ar /= k;
    LL tmp = n;
    for(int i = 2; i*i <= tmp; i++){
        if(tmp%i) continue;
        p.pb(i);
        while((tmp%i)==0) tmp /= i;
    }
    if(tmp>1) p.pb(tmp);
    tmp = m;
    //for(int i: p) pr(i), sp; ln;
    for(int i = 2; i*i <= tmp; i++){
        if(tmp%i) continue;
        p.pb(i);
        while((tmp%i)==0) tmp /= i;
    }
    if(tmp>1) p.pb(tmp);
    p.pb(2);
    tmp = ar;
    for(int i = 0; i < (int)p.size(); i++){
        if(tmp%p[i]) continue;
        p1.pb(p[i]);
        while((tmp%p[i])==0) tmp /= p[i];
    }
    //printf("ar:%lld\n",ar);
    //for(int i: p1) pr(i), sp; ln;
    //printf("ar:%lld\n",ar);
    dfs(0,1);
    return 0;
}
