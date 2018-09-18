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

int n, h, l[maxn], r[maxn];
LL sum[maxn];

int main(){
    sc(n); sc(h);
    for(int i = 0; i < n; i++){
        sc(l[i]); sc(r[i]);
    }
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + l[i]-r[i-1];
    }
    LL ans = 0;
    sum[n] = 1e12+10;
    for(int i = 0; i < n; i++){
        if(sum[i+1]-sum[i] >= h){
            //printf("i:%d\n",i);
            ans = max(ans, 1LL*r[i]-l[i]+h);
            continue;
        }
        int L = i+1, R = n;
        while(L+1 < R){
            int mid = (L+R)/2;
            if(h > (sum[mid]-sum[i])) L = mid;
            else R = mid;
        }
        LL x1 = l[i], x2 = h-(sum[L]-sum[i])+r[L];
        ans = max(ans, x2-x1);
    }
    cout << ans << endl;
    return 0;
}
