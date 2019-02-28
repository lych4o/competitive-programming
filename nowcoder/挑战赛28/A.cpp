#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef double db;
const db PI = acos(-1.0);
const LL mod = 1e9+7;
const int maxn = 1e6+10;

LL a,b,L;
pii play(LL x, LL y){
    LL y0=y;
    y = (2*y0-y+x-1)/x*x + y;
    return mk(x,y);
}
int main(){
    cin >> a >> b >> L;
    int win=-1;
    for(LL x=a,y=b,t=1;;t++){
        //printf("x:%lld,y:%lld\n",x,y);
        if(x>L){
            win=t%2;
            break;
        } 
        pii nxt=play(x,y);
        x = nxt.S; y = nxt.F;
    }
    if(win) printf("Yes ");
    else printf("No ");

    win=-1;
    for(LL x=b,y=a,t=0;;t++){
        if(x>L){
            win=t%2;
            break;
        }
        pii nxt=play(x,y);
        x=nxt.S; y=nxt.F;
    }
    if(win) printf("Yes ");
    else printf("No ");
    puts("");
    return 0;
}
