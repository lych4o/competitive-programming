#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1e6+10;

int p[maxn], pnum, nop[maxn];
void init(){
    for(int i = 2; i < maxn; i++){
        if(!nop[i]) p[pnum++] = i;
        for(int j = 0; i*p[j] < maxn; j++){
            nop[i*p[j]] = 1;
            if(i%p[j] == 0) break;
        }
    }
}

int vis[maxn], n;
queue<int> q;
void bfs(){
    memset(vis, 0, sizeof(vis));
    q.push(n);
    vis[n] = 1;
    while(q.size() > 0){
        int u = q.front(); q.pop();
        for(int i = 0; i < pnum && p[i]*p[i] <= u; i++){
            if(!vis[u/p[i]]) q.push(vis[u/p[i]]), vis[u/p[i]] = 1;
        }
    }
}

int main(){
    init();
    while(cin >> n){
        /*bfs();
        int cnt = 0;
        for(int i = 0; i <= n; i++){
            if(vis[i]) printf("%d\n",i), cnt++;
        }
        printf("cnt:%d\n", cnt);*/
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(vis[n/i]) continue;
            printf("n/%d = %d\n",i,n/i);
            vis[n/i] = 1;
            cnt++;
        }
        printf("cnt = %d\n",cnt);
        for(int i = 1; i <= n; i = n/(n/i)+1)
            printf("i:%d\n", i);
    }
    return 0;   
}
