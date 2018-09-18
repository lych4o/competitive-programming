#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<set>
#define mk make_pair
#define fout fflush(stdout)
#define pii pair<int,int>
#define sc(x) scanf("%d", &x)
#define fi first
#define se second
using namespace std;

typedef long long LL;
const int maxn = 2e5+10;

int x[maxn], y[maxn], cnt[maxn], n, a[maxn];

int main(){
    sc(n); 
    for(int i = 1; i < n; i++){
        sc(x[i]); sc(y[i]);
        cnt[x[i]]++; cnt[y[i]]++;
    }   
    a[0] = n;
    int r = 0, l = 1;
    if(cnt[n] != n-1) return puts("NO"), 0;
    for(int i = n-1; i >= 1; i--){
        if(cnt[i] > 0){
            a[r+cnt[i]] = i;
            r += cnt[i];
            if(r >= n) return puts("NO"), 0;
        }else{
            while(a[l]>0) l++;
            if(l > r) return puts("NO"), 0;
            a[l] = i;
        }
    }
    puts("YES");
    for(int i = 1; i < n; i++){
        printf("%d %d\n",a[i-1],a[i]);
    }
    return 0;
}
