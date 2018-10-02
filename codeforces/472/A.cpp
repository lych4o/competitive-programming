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
#define sz(x) int((x).size())
using namespace std;
typedef long long LL;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int maxn = 55;
int n, m;
char s[maxn][maxn];

int checkr(){
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        int f1=0, f2=0;
        for(int k=1; k<=m ;k++){
            if(s[i][k]=='#'&&s[j][k]=='#') f1=1;
            if(s[i][k]!=s[j][k]) f2=1;
        }
        //printf("r1:%d,r2:%d,f1:%d,f2:%d\n",i,j,f1,f2);
        if(f1&&f2) return 0;
    }
    return 1;

}
int checkc(){
    for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++){
        int f1=0, f2=0;
        for(int k=1; k<=n ;k++){
            if(s[k][i]=='#'&&s[k][j]=='#') f1=1;
            if(s[k][i]!=s[k][j]) f2=1;
        }
        //printf("c1:%d,c2:%d,f1:%d,f2:%d\n",i,j,f1,f2);
        if(f1&&f2) return 0;
    }
    return 1;
}
int main(){
    sc(n); sc(m);
    for(int i = 1; i <= n; i++) scanf("%s", s[i]+1);
    if(checkr()&&checkc()) puts("Yes");
    else puts("No");
    return 0;
}
