#include<iostream>
#include<cstdio>

using namespace std;

typedef long long LL;
const int maxn = 105, mod = ;

LL dp[maxn][3][3], ans[maxn];

LL add(LL& a, LL b){
    return a=(a+b)%mod;
}
int main(){
    ans[1] = 3;
    ans[2] = 3*3;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++){
        dp[2][i][j] = 1;
    }
    for(int i = 2; i < 3; i++){
        for(int o = 0; o < 3; o++) for(int p = 0; p < 3; p++) for(int q = 0; q < 3; q++){
            if(o==p && p==q) continue;
            if(o==q && a==2) continue;
            if(
        }
    }
    return ;
}
