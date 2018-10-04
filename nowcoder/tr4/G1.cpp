#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
//const LL mod = 1e9+7;
const int maxn = 1e3+10;
int n, cnt[maxn][maxn];
LL a[maxn], w[maxn];
int main(){
    while(sc(n)!=EOF){
    //for(int i = 1; i <= n; i++) sll(a[i]);
    //for(int i = 1; i <= n; i++) sll(w[i]);
    for(int i = 1; i <= n; i++){
        printf("cnt[%d]:",i);
        for(int j = 1; j <= n; j++){
            cnt[i][j]=min(n,i+j-1)-max(1,i-j+1)+1-j+1;
            printf("%d ",cnt[i][j]);
        }
        puts("");
    }
    puts("");
    }
    return 0;
}
