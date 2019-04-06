#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
const int maxn = 1e6+10;

pLL s, t; 
int n;
LL sx[maxn], sy[maxn];
char str[maxn];
inline pLL add(pLL p, pLL q){ return mk(p.F+q.F,p.S+q.S);}
inline pLL su(pLL p, pLL q){ return mk(p.F-q.F,p.S-q.S);}
inline LL dis(pLL p, pLL q){return abs(p.F-q.F)+abs(p.S-q.S);}
int main(){
    scanf("%lld%lld%lld%lld",&s.F,&s.S,&t.F,&t.S);
    sc(n);
    scanf("%s", str);
    for(int i=1;i<=n;i++){
        if(str[i-1]=='U') sy[i]++;
        if(str[i-1]=='D') sy[i]--;
        if(str[i-1]=='L') sx[i]--;
        if(str[i-1]=='R') sx[i]++;
        sx[i] += sx[i-1];
        sy[i] += sy[i-1];
    }
    pLL nxt = add(s,mk(sx[n],sy[n]));
    if(dis(s,t) == 0) return printf("0\n"), 0;
    LL L=-1, R=1e16+10;
    while(L+1<R){
        LL mid = (L+R)>>1;
        pLL d = add(mk(mid/n*sx[n],mid/n*sy[n]), mk(sx[mid%n], sy[mid%n]));
        nxt = add(d, s);
        //printf("mid:%lld\n",mid);
        //printf("mid/n:%lld, sx:%lld, sy:%lld, mid%%n:%lld, sx:%lld, sy:%lld\n",
         //   mid/n,sx[n],sy[n],mid%n,sx[mid%n],sy[mid%n]);
        //printf("nxt:(%lld,%lld), (%lld,%lld)+(%lld,%lld)\n",nxt.F,nxt.S,mid/n*sx[n],mid/n*sy[n],sx[mid%n],sy[mid%n]);
        if(dis(nxt,t) <= mid) R = mid;
        else L = mid;
    }
    if(R>1e16) cout << -1 << endl;
    else cout << R << endl;
    return 0;
}
