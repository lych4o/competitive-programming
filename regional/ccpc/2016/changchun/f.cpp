#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define pb push_back
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 1e4+10;
int n, k, a[maxn];
int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); sc(k);
        int p = 0;
        if(k%2){
            a[p++] = 2*k;
            for(int i = k; i >= 1; i--) a[p++] = i;
            for(int i = k+1; i <= n; i++){
                if(i == k*2) continue;
                a[p++] = i;
            }
        }else{
            a[p++] = k; a[p++] = 2*k;
            for(int i = 1; i <= n; i++){
                if(i == k || i == k*2) continue;
                a[p++] = i;
            }
        }
        printf("Case #%d:", kase);
        for(int i = 0; i < n; i++){
            printf(" %d", a[i]);
        }puts("");
    }
    return 0;
}
