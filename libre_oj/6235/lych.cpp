#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#define fout fflush(stdout)
using namespace std;
typedef long long LL;

const int maxn = 1e6+10;
int nop[maxn], p[maxn], pnum;
void init(){
    p[0] = 1;
    for(int i = 2; i < maxn; i++){
        if(!nop[i]) p[++pnum] = i;
        for(int j = 1; p[j]*i < maxn; j++){
            nop[i*p[j]] = 1;
            if(i % p[j] == 0) break;
        }
    }
}

int tot;
LL v1[maxn], v2[maxn], val[maxn], n, nn, g[maxn];

inline int id(LL x){
    return x <= nn ? v1[x] : v2[n/x];
}
LL calcG(){
    tot = 0;
    nn = (LL)sqrt(n);
    for(LL i = 1; i <= n; i = n/(n/i)+1){
        if(n/i <= i) v1[n/i] = tot;
        else v2[n/(n/i)] = tot;
        val[tot] = n/i;
        g[tot++] = n/i - 1;
    }
    for(int j = 1; j <= pnum; j++){
        for(int i = 0; i<tot && 1LL*p[j]*p[j] <= val[i]; i++){
            int x = id(val[i]/p[j]);
            //g[i] -= g[x]-g[id(p[j-1])];
            g[i] -= g[x]-j+1;
        }
    }
    return g[id(n)];
}

int main(){
    init();
    cin >> n;
    cout << calcG() << endl;
    return 0;   
}
