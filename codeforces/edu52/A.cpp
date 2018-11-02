#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define ln puts("")
#define sp putchar(' ')
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fout fflush(stdout)
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
//const LL mod = 1e9+7;
//const int maxn = 1e6+10;

LL s,a,b,c;

int main(){
    int T; cin >> T;
    while(T--){
        cin >>s>>a>>b>>c;
        LL t = s/c;
        cout << s/c+t/a*b<<endl;
    }
    return 0;
}
