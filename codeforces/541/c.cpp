#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define F first
#define S second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int maxn = 1e6+10;

int n, m, a[maxn], b[maxn];
int main(){
    sc(n); for(int i=0;i<n;i++) sc(a[i]);
    sort(a,a+n);
    if(n%2){
        int flg=1;
        for(int i=0, p=0;i<n;i++){
            b[i] = a[p];
            p += 2*flg;
            if(p >= n) p=n-2, flg = -1;
        }
    }else{
        int flg=1;
        for(int i=0,p=0;i<n;i++){
            b[i] = a[p];
            p += 2*flg;
            if(p >= n) p=n-1, flg = -1;
        }
    }
    for(int i=0;i<n;i++) printf("%d%c", b[i], i==n-1?'\n':' ');
    return 0;
}
