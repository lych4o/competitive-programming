#include<iostream>
#include<cstdio>
#define sc(x) scanf("%d", &x)
#define pr(x) printf("%d\n",x);
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
    //for(int kase = 1; kase <= 80; kase++){
        LL n; scanf("%lld", &n);
        //LL n = kase;
        printf("Case #%d: ",kase);
        if(n <= 5){
            if(n==0) pr(1);
            if(n==1) pr(9);
            if(n==2) pr(41);
            if(n==3) pr(109);
            if(n==4) pr(205);
            if(n==5) pr(325);
        }else{
            printf("%llu\n", 325+(64+14uLL*n)*1uLL*(n-5LL));
        }
    }
    return 0;
}
