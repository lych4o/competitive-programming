#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define F first
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;
const int maxn = 5e6+10;
int n, a[maxn], sum[maxn];
char s[maxn];
int main(){
    int T; sc(T);
    for(int kase=1;kase<=T;kase++){
        sc(n); scanf("%s",s);
        for(int i=0;i<n;i++){
            a[i+1]=s[i]-'0';
        }
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        int len=(n+1)/2;
        int mx=0;
        for(int i=len;i<=n;i++){
            mx = max(mx, sum[i]-sum[i-len]);
        }
        printf("Case #%d: %d\n",kase,mx);
    }
    return 0;
}
