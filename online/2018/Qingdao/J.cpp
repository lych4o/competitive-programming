#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define sc(x) scanf("%d", &x)
#define pb push_back

using namespace std;
typedef long long LL;
//const int maxn = 1e6+10;

LL gcd(LL x, LL y){return x?gcd(y%x,x):y;}
LL a,b,c,d,v,t;

int main(){
    int T; sc(T);
    while(T--){
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
        LL now = 0, cnt = 0, beg = (min(a,c) <= v);
        for(now = 0; ; now += a){
            LL pre = now%c ? now%c : c;
            pre = min(a, pre);
            cnt += b-(pre>v);
            if((now+a)%c == 0) break;
        }
        for(now = 0; ; now += c){
            LL pre = min(c, now%a);
            cnt += d-(pre>v);
            if((now+c)%a == 0) break;
        }
        LL lcm = a*c/gcd(a,c);
        LL times = (t+1)/lcm;
        LL ans = times*cnt;
        //printf("ans:%lld, times:%lld, lcm:%lld, cnt:%lld, beg:%lld\n",
          //      ans,times,lcm,cnt,beg);
        for(now = times*lcm; now <= t; now += a){
            LL pre = now%c ? now%c : c;
            pre = min(a, pre);
            ans += b-(pre>v);
        }
        for(now = times*lcm; now <= t; now += c){
            LL pre = min(c, now%a);
            ans += d-(pre>v);
        }
        ans -= beg;
        cout << ans << endl;
    }
    return 0;
}
