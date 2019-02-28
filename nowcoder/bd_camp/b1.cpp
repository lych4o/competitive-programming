#include<bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define F first
#define pb push_back
#define S second
#define mk make_pair
#define pii pair<int,int>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e6+10;
vector<pii> vp[2];
int a[maxn], p[maxn], n, bit[maxn];
void add(int x){for(int i=x;i<n+5;i+=i&-i)bit[i]++;}
int sum(int x){int ret=0; for(int i=x;i>0;i-=i&-i) ret+=bit[i]; return ret;}
void clr(int x){for(int i=x;i<n+5;i+=i&-i)bit[i]=0;}
int main(){
    int T; sc(T);
    while(T--){
        sc(n);
        vp[0].clear(); vp[1].clear();
        int now=0;
        for(int i=1;i<=n;i++){
            int tmp; sc(tmp);
            p[tmp]=i;
        }
        for(int i=2;i<=n;i++){
            if(i==0) continue;
            int mn=min(p[i-1],p[i]), mx=max(p[i-1],p[i]);
            vp[now].pb(mk(mn,mx));
            now ^= 1;
        }
        sort(ALL(vp[0])); sort(ALL(vp[1]));
        int flg=1;
        for(int i=0;i<sz(vp[0]);i++){
            //printf("(%d,%d) ",vp[0][i].F,vp[0][i].S);
            if(sum(vp[0][i].S)-sum(vp[0][i].F)) flg=0;
            add(vp[0][i].S); 
        }//puts("");
        for(int i=0;i<sz(vp[0]);i++) clr(vp[0][i].S);
        for(int i=0;i<sz(vp[1]);i++){
            //printf("(%d,%d) ",vp[1][i].F,vp[1][i].S);
            if(sum(vp[1][i].S)-sum(vp[1][i].F)) flg=0;
            add(vp[1][i].S); 
        }//puts("");
        for(int i=0;i<sz(vp[1]);i++) clr(vp[1][i].S);
        if(flg) puts("Yes");
        else puts("No");
    }
    return 0;
}
