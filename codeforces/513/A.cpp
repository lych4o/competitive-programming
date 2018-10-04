#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
using namespace std;

char s[200];

int main(){
    int n; sc(n);
    scanf("%s", s);
    int cnt=0;
    for(int i = 0; i < n; i++){
        cnt += s[i]=='8';
    } 
    cout << min(n/11,cnt) << endl;
    return 0;
}
