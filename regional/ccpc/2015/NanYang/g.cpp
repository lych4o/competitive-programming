#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;

char s[12][12];
int vis[12][12], bnd[12][12];
int dr[]={0,0,1,-1},dc[]={1,-1,0,0};

queue<int> q;
int bfs(int x, int y){
    memset(bnd,0,sizeof(bnd));
    while(q.size()) q.pop();
    vis[x][y]=1;
    q.push(x*20+y);
    int cnt = 0;
    while(q.size()){
        int now = q.front(); q.pop();
        int r = now/20, c = now%20;
        for(int i = 0; i < 4; i++){
            int rr = r+dr[i], cc = c+dc[i];
            if(rr>9||rr<1||cc<1||cc>9) continue;
            if(s[rr][cc]=='.'&&bnd[rr][cc]==0) bnd[rr][cc]=1, cnt++;
            else if(s[rr][cc]=='o' && vis[rr][cc]==0)
                vis[rr][cc]=1, q.push(rr*20+cc);
        }
    }
    //printf("bfs(%d,%d):%d\n",x,y,cnt);
    return cnt==1;
}

int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        for(int i = 1; i <= 9; i++) scanf("%s", s[i]+1);
        memset(vis, 0, sizeof(vis));
        int flg = 0;
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                if(s[i][j]=='o' && !vis[i][j]) flg |= bfs(i,j);
            }
        }
        if(flg) printf("Case #%d: Can kill in one move!!!\n",kase);
        else printf("Case #%d: Can not kill in one move!!!\n",kase);
    }
    return 0;
}
