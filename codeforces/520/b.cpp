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
//const int maxn = 1e6+10;
LL n;
vector<int> v;
int main(){
    sll(n);
    LL ans=1, tmp = n, mx=0;
    if(n==1){
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    for(LL i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            int cnt=0;
            while(tmp%i==0) tmp/=i,cnt++;
            ans *= i;
            mx = max(mx, 1LL*cnt);
            v.pb(cnt);
        }
    }
    if(tmp>1) ans *= tmp, mx=max(mx,1LL), v.pb(1);
    int flg=0;
    for(int i:v) if(i<mx) flg=1;
    LL x=1, ans2=0;
    while(x<mx) x*=2,ans2++;
    if(flg||mx<x) ans2++;
    printf("%lld %lld\n",ans,ans2);
    return 0;
}
