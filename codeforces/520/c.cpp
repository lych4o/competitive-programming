#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 1e6+10;
int n, q, sum[maxn];
char s[maxn];
LL pw[maxn];
int main(){
    sc(n); sc(q);
    scanf("%s",s);
    pw[0]=1;
    for(int i=1;i<maxn;i++){
        pw[i]=pw[i-1]*2%mod;
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(s[i-1]-'0');
        //printf("sum[%d]:%d\n",i,sum[i]);
    }
    while(q--){
        int l,r;
        sc(l); sc(r);
        int s1=sum[r]-sum[l-1],s0=r-l+1-s1;
        LL ss1=(pw[s1]-1+mod)%mod,
           ss2=ss1*(pw[s0]-1+mod)%mod;
        cout << (ss1+ss2)%mod << endl;
    }
    return 0;
}
