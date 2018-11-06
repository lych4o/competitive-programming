#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
const int maxn = 1e7+10;
vector<int> prm;
int nop[maxn], stp[maxn];
void init(){
    for(int i = 2; i < maxn; i++){
        if(!nop[i]){
            prm.pb(i);
            stp[i] = 1;
        }
        for(int j = 0; i*prm[j] < maxn; j++){
            nop[i*prm[j]] = 1;
            stp[i*prm[j]] = stp[i]+1;
            if(i%prm[j]==0) break;
        }
    }
}

int w, h;
int main(){
    freopen("funny.in","r",stdin);
    freopen("funny.out","w",stdout);
    init();
    while(scanf("%d%d",&w,&h)!=EOF){
        if(w==0 && h==0) break;
        printf("%d %d - ", w, h);
        if(stp[w]>stp[h]) printf("Vera\n");
        else puts("Harry");
    }
    return 0;
}
