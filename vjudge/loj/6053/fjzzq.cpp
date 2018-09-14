#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
typedef unsigned us;
typedef unsigned long long ull;
const us MOD=1e9+7;
#define SS 2333333
ll n,c0[SS],c1[SS],b0[SS],b1[SS]; int S,ps[SS/10],pn=0;
inline ull F(ull x,us g)
{
    if(x<=1||ps[g]>x) return 0;
    ull ans=((x>S)?b1[n/x]:c1[x])-c1[ps[g-1]]+MOD; //注意这里原来有bug
    for(us j=g;j<=pn&&ps[j]*(ll)ps[j]<=x;++j)
    {
        ull cn=x/ps[j],ce=ps[j]*(ll)ps[j];
        for(us e=1;cn>=ps[j];++e,cn/=ps[j],ce*=ps[j])
            ans+=F(cn,j+1)*(ps[j]^e)+(ps[j]^(e+1)),ans%=MOD;
    }
    return ans%MOD;
}
int main()
{
    cin>>n; S=sqrtl(n);
    for(int i=1;i<=S;++i)
    {
        ll t=(n/i)%MOD; b0[i]=t;
        b1[i]=t*(t+1)/2%MOD; c0[i]=i;
        c1[i]=i*(ll)(i+1)/2%MOD;
    }
    for(int i=2;i<=S;++i)
    {
        if(c0[i]==c0[i-1]) continue; //not a prime
        ll x0=c0[i-1],x1=c1[i-1],r=(ll)i*i; ps[++pn]=i;
        int u=min((ll)S,n/(i*(ll)i)),uu=min(u,S/i);
        for(int j=1;j<=uu;++j)
            b1[j]-=(b1[j*i]-x1)*i,
            b0[j]-=b0[j*i]-x0;
        ll t=n/i;
        if(t<=2147483647)
        {
        int tt=t;
        for(int j=uu+1;j<=u;++j)
            b1[j]-=(c1[tt/j]-x1)*i,
            b0[j]-=c0[tt/j]-x0;
        }
        else
        {
        for(int j=uu+1;j<=u;++j)
            b1[j]-=(c1[t/j]-x1)*i,
            b0[j]-=c0[t/j]-x0;
        }
        for(int j=S;j>=r;--j)
            c1[j]-=(c1[j/i]-x1)*i,
            c0[j]-=c0[j/i]-x0;
    }
    for(int i=1;i<=S;++i)
    {
        c1[i]-=c0[i];
        b1[i]-=b0[i];
        if(i>=2) c1[i]+=2;
        if(n>=2LL*i) b1[i]+=2;
        c1[i]=(c1[i]%MOD+MOD)%MOD;
        b1[i]=(b1[i]%MOD+MOD)%MOD;
    }
    ps[pn+1]=S+1;
    ll ans=1+F(n,1);
    ans=(ans%MOD+MOD)%MOD;
    printf("%d\n",int(ans));
}
