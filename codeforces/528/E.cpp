#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
using namespace std;
const int maxn = 1e5+10;
int n,k,tv[26],tt[26],vis[26],tb[26],ps;
char s[maxn],a[maxn],b[maxn];
int check(){
    for(int i=0;i<n;i++) if(a[i]!=b[i]){
        if(a[i]>b[i]) return -1;
        else return i;
    }
    return n;
}
int main(){
    int T; sc(T);
    while(T--){
        sc(k); scanf("%s%s%s",s,a,b); n=strlen(s);
        if((ps=check())<0){
            puts("NO");
            continue;
        }
        memset(tt,-1,sizeof(tt));
        for(int i=0;i<ps;i++){
        
        }
    }
    return 0;
}
