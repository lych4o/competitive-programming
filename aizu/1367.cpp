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

const int maxn = 2e5+100;

int head, nxt[maxn], pre[maxn], n, m;

void print()
{
    //printf("link:\n");
    for(int i = head, cnt = 0; cnt < n; i = nxt[i], cnt++)
        printf("%d\n", i+1);
}
int main()
{
    //frein;
    //freout;
    while(scanf("%d%d", &n, &m) != EOF){
        head = 0;
        for(int i = 0; i < n; i++){
            nxt[i] = (i+1)%n;
            pre[i] = (i-1+n)%n;
        }

        while(m--){
            int k; sc(k); k--;
            if(head == k) continue;
            nxt[pre[k]] = nxt[k];
            pre[nxt[k]] = pre[k];
            nxt[pre[head]] = k;
            pre[k] = pre[head];
            pre[head] = k;
            nxt[k] = head;
            head = k;
            //print();
        }
        print();
    }
    return 0;
}
