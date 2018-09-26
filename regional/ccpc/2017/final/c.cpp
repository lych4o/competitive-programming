#include<iostream>
#include<cstdio>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
LL x, y, k;

int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        scanf("%lld%lld%lld",&x,&y,&k);
        swap(x,y);
        if(y > x){
            printf("Case #%d: %lld\n",kase, k);
            continue;
        }
        for(int i = k; i >= 0; i--){
            LL add = 11*(k-i)*y, minu = i*(11*x-9*y);
            //printf("i:%d,add:%lld,minu:%lld\n",i,add,minu);
            if(add - minu >= 0){
                printf("Case #%d: %d\n",kase, i);
                break;
            }
        }
    }
    return 0;
}
