#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define pLL pair<LL, LL>
#define pb push_back
#define mk make_pair
#define sp putchar(' ')
#define ln puts("")
#define fi first
#define fout fflush(stdout)
#define sqr(x) ((x)*(x))
#define ALL(x) x.begin(), x.end()
#define se second
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;

LL n, k;
char s[20];
int query(LL a, LL b){
    printf("%I64d %I64d\n", a, b); fout;
    scanf("%s", s);
    return s[0]=='Y';
}
int main(){
    srand(time(NULL));
    sll(n); sll(k);
    LL l = 1, r = n+1;
    while(1){
        if(r-l <= 5*k+10){
            LL p = l+(rand()%(r-l));
            if(query(p,p)) return 0;
            else l=max(1LL,l-k), r=min(n+1,r+k);
        }else{
            LL mid = (l+r)>>1;
            if(query(l,mid-1)) l=max(1LL,l-k),r=min(n+1,mid+k);
            else l=max(1LL,mid-k),r=min(n+1,r+k);
        }
    }
    return 0;
}
