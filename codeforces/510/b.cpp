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
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

int n, c[maxn], p[8], ans;
char s[maxn];

void dfs(int pos, int now, int sum){
    //printf("dfs(%d,%d,%d)\n",pos,now,sum);
    if(pos == 8){
        if(now != 7) return;
        ans = min(ans, sum);
        return;
    }
    dfs(pos+1, now, sum);
    if(p[pos] < INF) dfs(pos+1,now|pos,sum+p[pos]);
}
int main(){
    sc(n);
    for(int i = 0; i < 8; i++) p[i] = INF;
    for(int i = 0; i < n; i++){
        sc(c[i]); scanf("%s", s);
        int vis[3] = {0,0,0}, len = strlen(s);
        for(int i = 0; i < len; i++){
            vis[s[i]-'A'] = 1;
        }
        int x = vis[0]+(vis[1]<<1)+(vis[2]<<2);
        p[x] = min(p[x], c[i]);
    }
    ans = INF;
    dfs(0,0,0);
    if(ans == INF) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
