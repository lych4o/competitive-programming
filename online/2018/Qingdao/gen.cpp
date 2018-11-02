#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 1e5;
int a[maxn];
int main(){
    freopen("g.in","w",stdout);
    int T = 10; printf("%d\n",T);
    while(T--){
        int n = maxn; printf("%d\n", n);
        for(int i = 0; i < n; i++) printf("%d ", rand()%maxn+1), a[i] = i+1; 
        puts("");
        random_shuffle(a,a+n);
        for(int i = 0; i < n; i++) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
