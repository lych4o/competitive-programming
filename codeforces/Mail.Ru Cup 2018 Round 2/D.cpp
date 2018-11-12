#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pii pair<int,int>
#define sll(x) scanf("%I64d",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 3e3+10;

int ps[maxn];
void get_next(char* s, int* nxt){
    int k=-1, n=strlen(s);
    nxt[0] = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
}
int match(char* t, char* s, int* nxt){
    get_next(s,nxt);
    int k=-1, m=strlen(t), n=strlen(s);
    for(int i = 0; i < m; i++){
        while(k >= 0 && t[i] != s[k+1])k = nxt[k];
        if(t[i] == s[k+1])k++;
        if(k == n-1) return i+1;
    }
    return 0;
}
int n, L[maxn], R[maxn], sz[maxn], nxt[maxn];
char s[maxn][maxn], t[maxn][maxn],ans[maxn],ans1[maxn];
vector<int> v;
vector<pii> pos;
int cmp(int i, int j){
    if(R[i]-L[i]!=R[j]-L[j]) return 0;
    for(int u=L[i],v=L[j];u<=R[i];u++,v++){
        if(s[i][u]!=s[j][v] || t[i][u]!=t[j][v]) return 0;
    }
    return 1;
}
int main(){
    sc(n);
    for(int i=1;i<=n;i++) scanf("%s",s[i]),L[i]=maxn,R[i]=-maxn,sz[i]=strlen(s[i]);
    for(int i=1;i<=n;i++) scanf("%s",t[i]);
    for(int i=1;i<=n;i++) for(int j=0;j<sz[i];j++)
        if(s[i][j]!=t[i][j]) L[i]=min(L[i],j),R[i]=max(R[i],j);
    for(int i=1;i<=n;i++) if(L[i]<maxn) v.pb(i);
    int p=v[0];
    for(int q: v) if(!cmp(p, q)) return puts("NO"), 0;

    while(1){
        int flg=1;
        for(int q: v) if(!L[q]||s[q][L[q]-1]!=s[p][L[p]-1]) flg=0;
        if(!flg) break;
        for(int q: v) L[q]--;
    }
    while(1){
        int flg=1;
        for(int q: v)
            if(R[q]==sz[q]-1||s[q][R[q]+1]!=s[p][R[p]+1]) flg=0;
        if(!flg) break;
        for(int q: v) R[q]++;
    }
    int len=0;
    for(int i=L[p];i<=R[p];i++){
        ans[len]=s[p][i];
        ans1[len++]=t[p][i];
    }
    ans[len]='\0'; ans1[len++]='\0';
    for(int i=1;i<=n;i++){
        if(L[i]==maxn){
            if(match(s[i], ans, nxt)) return puts("NO"),0;
        }else{
            //int r=match(s[i],ans,nxt),l=r-len+1;
            //if(!(l<=L[i]&&R[i]<=r)) return puts("NO"), 0;
            if(match(s[i],ans,nxt)!=R[i]+1) return puts("NO"),0;
        }
    }
    printf("YES\n%s\n%s",ans,ans1);
	return 0;
}

