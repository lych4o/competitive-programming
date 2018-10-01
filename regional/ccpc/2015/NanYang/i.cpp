#include<bits/stdc++.h>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define fout fflush(stdout)
using namespace std;

const int mod = 1e9+7;
const int maxn = 205;

void add(int &x, int y){ x = (x+y)>=mod?(x+y-mod):(x+y);}
int id[(1<<19)], st[maxn], to[maxn][5], tot;
void print(int x){
    for(int i = 0; i < 18; i++)
        printf("%d",(x>>i)&1);
}
inline int encode(int n2, int n1, int p){ return p+n1*2+n2*6;}
inline void decode(int c, int& n2, int &n1, int &p){ p=c%2,n1=c/2%3,n2=c/6;}
inline int tran(int s, int x, int chs){
    int n2, n1, p; decode(s,n2,n1,p);
    chs = (chs&&!p);
    x -= n1+n2+2*chs;
    if(x < 0) return -1;
    if(x >= 3) x -= 3;
    return encode(n1, x, chs|p);
}
void Find_nxt(int now){
    //printf("Find(%d):\n",now); fout;
    for(int x = 0; x <= 4; x++){
        int nxt = 0;
        for(int c = 0; c < 18; c++){
            if((now&(1<<c))==0) continue;
            //printf("c:%d\n",c); fout;
            for(int chs=0; chs<2; chs++){
                int nc = tran(c, x, chs);
                if(nc >= 0) nxt |= (1<<nc);    
            }
        } 
        to[id[now]][x] = nxt;
        //printf("to[%d][%d]:%d\n",now,x,nxt);
        //printf("to["); print(now);printf("][%d]:",x); print(nxt); puts(""); fout;
    }
}
queue<int> q;
void bfs(){
    memset(id,-1,sizeof(id));
    while(q.size()) q.pop();
    int now = 0|(1<<0);
    q.push(now);
    id[now] = tot; st[tot++] = now;
    while(q.size()){
        now = q.front(); q.pop();
        int idn = id[now];
        //printf("tot:%d\n",tot); fout;
        Find_nxt(now);
        for(int i = 0; i <= 4; i++){
            int nxt = to[idn][i];
            if(id[nxt] >= 0) continue;
            q.push(to[idn][i]);
            id[nxt] = tot; st[tot++] = nxt;
        }
    }
    //printf("tot:%d\n",tot);
}

int dp[maxn][maxn][80];

void debug(){
    for(int i = 0; i < 18; i++){
        int n1,n2,p; decode(i,n2,n1,p);
        printf("decode(%d):(%d,%d,%d)\n",i,n2,n1,p);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                printf("encode(%d,%d,%d):%d\n",i,j,k,encode(i,j,k));               
            }
        }
    }
}

int main(){
    //debug();
    bfs();
    int T; cin >> T;
    for(int kase = 1; kase <= T; kase++){
        int k, m; sc(k); sc(m);
        memset(dp,0,sizeof(dp));
        dp[0][0][id[1]] = 1;
        for(int i=0;i<k;i++)for(int j=0;j<=m;j++)for(int s=0;s<tot;s++)
        if(dp[i][j][s]>0) for(int x=0;x<=4&&x+j<=m;x++){
            //printf("dp(%d,%d,%d)-->dp(%d,%d,%d)\n",i,j,st[s],i+1,j+x,to[s][x]);
            add(dp[i+1][j+x][id[to[s][x]]], dp[i][j][s]);
        }
        int ans = 0;
        for(int i=0;i<tot;i++) if(st[i]&2){
            //printf("dp[%d][%d][%d]:%d\n",k,m,st[i],dp[k][m][i]);
            add(ans,dp[k][m][i]);
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
