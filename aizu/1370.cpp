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
#include <unordered_set>

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
//const ll mod = 772002;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int sgm_siz = 26, maxl = 4e3+100;
int a[26],len1,len2;
char s1[maxl],s2[maxl];
unordered_set<ull> s;

ull hashh()
{
    ull sum = 26;
    for(int i = 0; i < 26; i++){
        sum *= mod;
        sum += a[i];
    }
    return sum;
}

int main()
{
    //frein;
    //freout;
    scanf("%s%s",s1,s2);
    len1 = strlen(s1); len2 = strlen(s2);
    for(int ans = min(len1, len2); ans > 0; ans--){
        memset(a,0,sizeof(a));
        s.clear();
        for(int i = 0; i < ans; i++) a[s1[i]-'a']++;
        s.insert(hashh());
        for(int i = 1; i <= len1-ans; i++){
            a[s1[i+ans-1]-'a']++;
            a[s1[i-1]-'a']--;
            s.insert(hashh());
        }
        memset(a, 0, sizeof(a));
        for(int i = 0; i < ans; i++) a[s2[i]-'a']++;
        if(s.count(hashh())){
            printf("%d\n", ans);
            return 0;
        }
        for(int i = 1; i <= len2-ans; i++){
            a[s2[i+ans-1]-'a']++;
            a[s2[i-1]-'a']--;
            if(s.count(hashh())){
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    printf("0\n");
    return 0;
}
