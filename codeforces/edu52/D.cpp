#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define ln puts("")
#define sp putchar(' ')
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fout fflush(stdout)
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
//const LL mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+10;

int n, a[maxn][maxn], inq[3][105][105];
pii d[3][105][105];
int dr[]={2,2,-2,-2,1,1,-1,-1},dc[]={1,-1,1,-1,2,-2,2,-2};
int pos[maxn];
struct hh{
    int ch,x,y;
    hh(int cc=0,int xx=0,int yy=0){
        ch=cc; x=xx; y=yy;
    }
};
queue<hh> q;
void Push(int ch,int x,int y, pii stp){
    /*if(ch==2){
    pii xxx = d[ch][x][y];
    printf("Push(%d,%d,%d,%d):(%d,%d),(%d,%d)\n",
            ch,x/10,x%10,y,stp.fi,stp.se,xxx.fi,xxx.se);
    }*/
    if(stp < d[ch][x][y]){
        d[ch][x][y] = stp;
        if(inq[ch][x][y]) return;
        q.push(hh(ch,x,y));
        inq[ch][x][y]=1;
    }
}
void bfs(){
    for(int i = 0; i < 3; i++)for(int j=0;j<105;j++)
    for(int k = 0; k < 105; k++)
        d[i][j][k] = mk(INF,INF);
    memset(inq,0,sizeof(inq));
    for(int i = 0; i < 3; i++){
        Push(i,pos[1],1,mk(0,0));
    }
    while(q.size()){
        hh h = q.front(); q.pop();
        int r = h.x/10, c = h.x%10, ch=h.ch, y=h.y, x = h.x;
        inq[ch][x][y] = 0;
        pii stp = d[ch][x][y];
        int pp = stp.fi, qq = stp.se;
        //if(ch==2) printf("d[%d][%d][%d][%d]:(%d,%d)\n",ch,r,c,y,pp,qq);
        //if(pp >= 400) continue;
        for(int nch = 0; nch < 3; nch++){
            if(nch==ch){
                if(ch==0){
                    for(int dir=0;dir<8;dir++){
                        int nr=r+dr[dir],nc=c+dc[dir],ny=y;
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(a[nr][nc] == y+1) ny++;
                        Push(ch,nr*10+nc,ny,mk(pp+1,qq));
                    }
                }else if(ch==1){
                    for(int i = -n; i <= n; i++){
                        int nr=r+i,nc=c+i,ny=y;
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(a[nr][nc] == y+1) ny++;
                        Push(ch,nr*10+nc,ny,mk(pp+1,qq));
                    }
                    for(int i = -n; i <=n; i++){
                        int nr=r+i,nc=c-i,ny=y;
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(a[nr][nc] == y+1) ny++;
                        Push(ch,nr*10+nc,ny,mk(pp+1,qq));
                    }
                }else{
                    for(int i = 0; i < n; i++){
                        int nr=i, nc=c,ny=y;
                        if(a[nr][nc]==y+1) ny++;
                        //printf("nr:%d,nc:%d,ny:%d\n",nr,nc,ny);
                        Push(ch,nr*10+nc,ny,mk(pp+1,qq));
                    }
                    for(int i = 0; i < n; i++){
                        int nr=r, nc=i,ny=y;
                        if(a[nr][nc]==y+1) ny++;
                        //printf("nr:%d,nc:%d,ny:%d\n",nr,nc,ny);
                        Push(ch,nr*10+nc,ny,mk(pp+1,qq));
                    }
                }
            }else{
                Push(nch,r*10+c,y,mk(pp+1,qq+1));
            }
        }
    }
}
int main(){
    sc(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sc(a[i][j]);
            pos[a[i][j]] = i*10+j;
        }
    }
    bfs();
    pii ans = mk(INF,INF);
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 105; i++){
            if(ans > d[j][i][n*n]){
                ans = min(ans, d[j][i][n*n]);
                //printf("d[%d][%d][%d][%d]:(%d,%d)\n",j,i/10,i%10,n*n,
                  //      d[j][i][n*n].fi,d[j][i][n*n].se);
            }
        }
    }
    cout << ans.fi << " " << ans.se << endl;
    return 0;
}
