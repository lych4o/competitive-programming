#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#define pb push_back
#define sc(x) scanf("%d",&x)
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long LL;

LL l,r;
int main(){
    cin >> l >> r;
    cout << "YES" << endl;
    for(LL i = l; i <= r; i += 2){
        printf("%lld %lld\n",i,i+1);   
    }
    return 0;
}
