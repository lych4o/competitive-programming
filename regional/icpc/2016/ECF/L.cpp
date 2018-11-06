#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;

int cnt[20][20][20][20];
void dfs(int D, int a, int b, int c, int d){
    if(D==0){
        dfs(D+1, a+3,b,c,d);
        dfs(D+1, a+1,b+1,c,d);
        dfs(D+1, a,b+3,c,d);
    }else if(D==1){
        dfs(D+1, a+3,b,c,d);
        dfs(D+1, a+1,b,c+1,d);
        dfs(D+1, a,b,c+3,d);
    }else if(D==2){
        dfs(D+1, a+3,b,c,d);
        dfs(D+1, a+1,b,c,d+1);
        dfs(D+1, a,b,c,d+3);
    }else if(D==3){
        dfs(D+1, a,b+3,c,d);
        dfs(D+1, a,b+1,c+1,d);
        dfs(D+1, a,b,c+3,d);
    }else if(D==4){
        dfs(D+1, a,b+3,c,d);
        dfs(D+1, a,b+1,c,d+1);
        dfs(D+1, a,b,c,d+3);
    }else if(D==5){
        dfs(D+1, a,b,c+3,d);
        dfs(D+1, a,b,c+1,d+1);
        dfs(D+1, a,b,c,d+3);
    }else if(D==6){
        cnt[a][b][c][d]++;
        return;
    }
}
int main(){
    int T; sc(T);
    dfs(0,0,0,0,0);
    for(int kase=1;kase<=T;kase++){
        int a,b,c,d; sc(a);sc(b);sc(c);sc(d);
        if(a>9) a=10; 
        if(b>9) b=10; 
        if(c>9) c=10;
        if(d>9) d=10;
        int x=cnt[a][b][c][d];
        printf("Case #%d: ", kase);
        if(x==1) puts("Yes");
        else if(x>1) puts("No");
        else puts("Wrong Scoreboard");
    }
    return 0;
}
