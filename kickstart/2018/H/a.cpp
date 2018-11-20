#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define F first
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const int sigma = 2;
char s[maxn];
LL dp[maxn];
inline int id(char c){
    if(c=='R') return 1;
    return 0;
}
struct Node{
    int nxt[maxn][sigma], num[maxn], idx, flg[maxn];
    LL dp[maxn];
    int newNode(){
        int x = ++idx;
        memset(nxt[x], -1, sizeof(nxt[x]));
        flg[x]=0;
        return x;
    }
    void init(){
        idx = 0;
        memset(dp,0,sizeof(dp));
        memset(nxt[0], -1, sizeof(nxt[0]));
    }
    void insert(){
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = id(s[i]);
            if(nxt[rt][u] == -1)nxt[rt][u] = newNode();
            rt = nxt[rt][u];
        }
        flg[rt]=1;
    }
} trie;
int n, p;
int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        trie.init();
        sc(n); sc(p);
        for(int i=0;i<p;i++) scanf("%s",s), trie.insert();
        trie.dp[0]=1;
        int ed=trie.newNode();
        for(int i=0;i<n;i++){
            memset(dp,0,sizeof(dp));
            for(int u=0;u<=trie.idx;u++){
                //printf("trie.dp[%d]:%lld\n",u,trie.dp[u]);
                if(trie.flg[u]) trie.dp[u]=0;
                for(int j=0;j<2;j++){
                    if(trie.nxt[u][j]==-1) dp[ed] += trie.dp[u];
                    else dp[trie.nxt[u][j]] += trie.dp[u];
                }
            }
            for(int u=0;u<=trie.idx;u++){
                trie.dp[u]=dp[u];
            }
        }
        printf("Case #%d: %lld\n",kase,trie.dp[ed]);
    }
    return 0;
}
