#include <bits/stdc++.h>
#define sll(x) scanf("%lld", &x)
#define sc(x) scanf("%d", &x)
using namespace std;
const int maxn = 2e7+10;
typedef long long LL;
LL inv[maxn], n, r, mod, p;

void init(){
    inv[0]=inv[1]=1;
    for(int i = 2; i < mod; i++){
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    }
}

int main()
{
    sll(n); sll(mod); sll(r);
    p = mod;
    init();
    if(n>=2*mod){
        if(r==0){
            printf("2 1\n");
        }else puts("-1 -1");
    }else if(n>=mod){
        if(r==0){
            int flg = 0;
            for(int i = 2; i <= n; i++){
                if(i != p){
                    flg = 1;
                    printf("%d 1\n", i);
                    break;
                }
            }
            if(!flg) puts("-1 -1");
        }else{
            LL x = 1;
            for(int i = 2; i <= n; i++) if(i!=mod){
                x = x*i%mod;
            }
            int flg = 0;
            for(int i = 1; i < mod; i++){
                if(x*i%mod == r){
                    flg = 1;
                    printf("%lld %d\n",mod,i);
                    break;
                }
            }
            if(!flg) puts("-1 -1");
        }
    }else{
        int flg = 0;
        LL x = 1;
        for(int i = 2; i <= n; i++) x=x*i%mod;
        for(int i = 2; i <= n; i++){
            LL q = r*inv[x]%mod*(i%p)%mod;
            if(q < i && q >= 1){
                flg = 1;
                printf("%d %lld\n", i, q);
                break;
            }
        }
        if(!flg) puts("-1 -1");
    }
    return 0;
}
