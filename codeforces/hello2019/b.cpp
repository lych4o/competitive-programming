#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n, flg;
int a[maxn];
void dfs(int p, int deg){
    if(p==n){
        if(deg%360==0) flg=1;
        return;
    }
    dfs(p+1,deg+a[p]);
    dfs(p+1,deg-a[p]);
}
int main(){
    sc(n);
    for(int i=0;i<n;i++) sc(a[i]);
    dfs(0,0);
    if(flg) printf("YES\n");
    else puts("NO");
    return 0;
}
