#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define sz(x) ((int)x.size())
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n, a[maxn], mn[maxn], mx[maxn], c1[maxn], c2[maxn];
char s[maxn];
int main(){
    sc(n);
    int ans = 0 , c0 = 0;
    for(int i=0;i<n;i++){
        scanf("%s", s);
        int len=strlen(s);
        for(int j=0;j<len;j++){
            a[i] += (s[j]=='(')?1:-1;
            mn[i] = min(mn[i], a[i]);
        } a[i]=0;
        for(int j=len-1;j>=0;j--){
            a[i] += (s[j]=='(')?1:-1;
            mx[i] = max(mx[i], a[i]);
        }
        //printf("%d: mn:%d, mx:%d, val:%d\n",i,mn[i],mx[i],a[i]);
        if(mn[i]&&mx[i]) continue;
        if(a[i]==0){
            c0++;
        }else if(a[i]<0){
            c2[-a[i]]++;
        }else{
            c1[a[i]]++;
        }
    }
    ans += c0/2;
    for(int i=1;i<maxn;i++){
        ans += min(c1[i], c2[i]);
    }
    cout << ans << endl;
    return 0;
}
