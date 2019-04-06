#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
    if(!a) return b;
    return gcd(b%a, a);
}
int main(){
    int T; cin >> T;
    while(T--){
        LL a, b; scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        if(gcd(a,b)==1){
            printf("1\n%lld %lld\n", a, b);
            continue;
        }
        if(a==b){
            if(a<5) printf("-1\n");
            else printf("2\n2 3\n%lld %lld\n", a-2, b-3);
            continue;
        }

    }
    return 0;
}
