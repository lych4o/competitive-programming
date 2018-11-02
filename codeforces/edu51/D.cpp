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

const int maxn = 105;
int n, cnt[maxn], a[maxn], ans[maxn];
vector<int> pos[maxn];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        sc(a[i]); cnt[a[i]]++;
        pos[a[i]].pb(i);
    }
    int cnt1=0, cnt2=0;
    for(int i = 0; i < maxn; i++){
        if(cnt[i]==1) cnt1++;
        if(cnt[i]==2) cnt2++;
    }
    if((cnt1%2)==1 && cnt1+2*cnt2==n) return puts("NO"),0;
    int id=0;
    for(int i = 0; i < maxn; i++){
        if(cnt[i]==1){
            ans[pos[i][0]] = id;
            id ^= 1;
        }else{
            for(int j=0; j < (int)pos[i].size(); j++){
                ans[pos[i][j]]=0;
            }
        }
    }
    if((cnt1%2)==1){
        for(int i = 0; i < maxn; i++){
            if(cnt[i]>2){
                ans[pos[i][0]] = 1;   
                break;
            }
        }
    }
    puts("YES");
    for(int i = 0; i < n; i++){
        if(ans[i]) printf("A");
        else printf("B");
    }
    return 0;
}
