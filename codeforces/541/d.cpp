#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn = 2e3+10, base=2000;

int n, m, bg[maxn], ls[maxn], val[maxn];
char s[maxn][maxn];
vector<int> v, tmp[2];
set<int> s1, s2;
int main(){
    sc(n); sc(m);
    for(int i=1;i<=n;i++) s1.insert(i);
    for(int i=n+1;i<=n+m;i++) s2.insert(i);
    for(int i=1;i<=n;i++){
        scanf("%s", s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j]=='>'){
                bg[i]++; ls[j+n]++;
            }else if(s[i][j]=='='){
                
            }else{
                bg[j+n]++; ls[i]++;
            }
        }
    }
    int now=0, nxt=1, mn;
    for(int i=1;i<=n+m;i++) if(ls[i]==0) tmp[now].pb(i);
    for(int value=2010;value>=0;value--){
        if(tmp[now].size()==0) {mn=value; break;}
        tmp[nxt].clear();
        for(int u: tmp[now]){
            if(u<=n) s1.erase(u);
            else s2.erase(u);
        }
        for(int u: tmp[now]){
            val[u] = value;
            if(u<=n) for(int v: s2){
                ls[v]--; if(ls[v]==0) tmp[nxt].pb(v);
            }else for(int v: s1){
                ls[v]--; if(ls[v]==0) tmp[nxt].pb(v);
            }
        }
        swap(now, nxt);
    }
    for(int i=1;i<=n+m;i++) if(val[i]==0) return puts("NO"), 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        char ch;
        if(val[i]>val[j+m]) ch='>';
        else if(val[i]==val[j+m]) ch='=';
        else ch='<';
        if(s[i][j]!=ch) return puts("NO"), 0;
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d%c", val[i]-mn, i==n?'\n':' ');
    for(int i=1;i<=m;i++) printf("%d%c", val[i+n]-mn, i==m?'\n':' ');
    return 0;
}
