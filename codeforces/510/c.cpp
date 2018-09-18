#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#define pii pair<int, int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define debug puts("???");
#define br puts("")
#define ALL(x) x.begin(),x.end()
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int INF = 0x3f3f3f3f;

int n, a[maxn];
vector<int> z;
int main(){
    sc(n);
    int cnt1=0, cnt2=0;
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        if(a[i] < 0) cnt1++;
        if(a[i] == 0) cnt2++, z.pb(i);
    }
    cnt1 %= 2;
    if(cnt1 && cnt2){
        int mx = -1e9-10, pos=0;
        for(int i = 1; i <= n; i++){
            if(a[i] >= 0) continue;
            if(a[i] > mx){
                mx = a[i]; pos = i;
            }
        }
        for(int i = 0; i < (int)z.size(); i++){
            printf("1 %d %d\n", z[i], pos);
        }
        int pp, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0 || i == pos) continue;
            cnt++; pp = i;
        }
        if(cnt <= 0) return 0;
        printf("2 %d\n", pos);
        for(int i = 1; i <= n; i++){
            if(i == pp || i == pos || a[i] == 0) continue;
            printf("1 %d %d\n", i, pp);
        }
    }else if(!cnt1 && cnt2){
        int pp = z[0];
        for(int i = 1; i < (int)z.size(); i++){
            printf("1 %d %d\n", z[i], pp);
        }
        if(cnt2 == n) return 0;
        printf("2 %d\n", pp);
        for(int i = 1; i <= n; i++) if(a[i] != 0){
            pp = i; break;
        }
        for(int i = 1; i <= n; i++){
            if(i == pp || a[i] == 0) continue;
            printf("1 %d %d\n", i, pp);
        }
    }else if(cnt1 && !cnt2){
        int mx = -1e9-10, pos=0;
        for(int i = 1; i <= n; i++){
            if(a[i] >= 0) continue;
            if(a[i] > mx){
                mx = a[i]; pos = i;
            }
        }
        printf("2 %d\n", pos);
        int pp = pos+1; if(pp > n) pp -= n;
        for(int i = 1; i <= n; i++){
            if(i == pp || i == pos) continue;
            printf("1 %d %d\n", i, pp);
        }
    }else{
        for(int i = 2; i <= n; i++){
            printf("1 %d %d\n", i, 1);
        }
    }
    return 0;
}
