#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e9+7;
const int mod=1e5+7;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(__gcd(a,b)==1){
            printf("1\n%lld %lld\n",a,b);
        }
        else{
            int flag=0;
            for(ll i=2;i<=100;i++){
                for(ll j=2;j<=100;j++){
                    if(__gcd(a-i,b-j)==1&&__gcd(i,j)==1){
                        printf("2\n%lld %lld\n",i,j);
                        printf("%lld %lld\n",a-i,b-j);
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
        }
    }
    return 0;
}

