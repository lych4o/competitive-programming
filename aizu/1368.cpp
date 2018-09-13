#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst first
#define scd second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int maxn = 15;

int tb[maxn][maxn], dig[5], tmp[5], cnt;

void get_dig(int now)
{
    dig[0] = now/1000;  now %= 1000;
    dig[1] = now/100;   now %= 100;
    dig[2] = now/10;    now %= 10;
    dig[3] = now;
}

int cal(int a[])
{
    int ans = 0;
    for(int i = 0; i < 4; i++){
        ans = tb[ans][a[i]];
    }
    return ans;
}

int check(int a[])
{
    int ans = 0;
    for(int i = 0; i < 5; i++){
        /*if(a[0] == 4){
            printf("check: ans:%d, a[i]:%d, reslt:%d\n",
                ans, a[i], tb[ans][a[i]]);
        }*/
        ans = tb[ans][a[i]];
    }
    return ans;
}

void print(int a[])
{
    for(int i = 0; i < 5; i++)
        printf("%d",a[i]);
    lb;
}
int main()
{
    //frein;
    //freout;
    cnt = 0;
    for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
        sc(tb[i][j]);

    for(int i = 0; i < 10000; i++){
        //printf("i:%d\n",i);
        int flg = 1;
        get_dig(i);
        dig[4] = cal(dig);
        //printf("dig:"); print(dig);
        memcpy(tmp, dig, sizeof(dig));
        for(int j = 0; j < 5; j++){
            if(j) tmp[j-1] = dig[j-1];
            for(int k = 0; k <= 9; k++){
                if(k == dig[j]) continue;
                tmp[j] = k;
                //printf("tmp:"); print(tmp);
                if(check(tmp) == 0) flg = 0;
                //printf("flg:%d\n", flg);
                if(flg == 0) break;
            }
            if(flg == 0) break;
        }
        //printf("aft:::::flg:%d\n",flg);
        for(int j = 0; j < 4; j++){
            if(flg == 0) break;
            memcpy(tmp, dig, sizeof(dig));
            swap(tmp[j], tmp[j+1]);
            if(tmp[j] == tmp[j+1]) continue;
            if(check(tmp) == 0) flg = 0;
        }
        //printf("flg:%d\n",flg);
        if(flg == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
