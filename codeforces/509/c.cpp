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

const int maxn = 2e5+10;
int n,m,d,ans[maxn];
pii a[maxn];
set<pii> st;

int check(int x){
    //printf("check(%d)\n",x); fout;
    st.clear();
    for(int i = 1; i <= x; i++){
        //printf("i:%d\n",i);
        st.insert(mk(-d-10,i));
    }
    for(int i = 1; i <= n; i++){
        set<pii>::iterator it = st.lower_bound(mk(a[i].fi-d,-1));
        if(it == st.begin()) return 0;
        it--;
        ans[a[i].se] = it->se;
        //printf("a[%d]:%d, it:(%d,%d)\n",i,a[i].fi,it->fi,it->se);
        st.erase(it);
        st.insert(mk(a[i].fi,ans[a[i].se]));
    }
    return 1;
}

int main(){
    sc(n); sc(m); sc(d);
    for(int i = 1; i <= n; i++){
        sc(a[i].fi); a[i].se = i;
    }
    sort(a+1,a+n+1);
    int l = 0, r = n+1;
    while(l+1 < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    check(r);
    for(int i = 1; i <= n; i++)
        printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}
