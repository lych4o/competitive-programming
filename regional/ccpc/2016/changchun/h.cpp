#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define pb push_back
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 1e6+10;
int s[maxn], t[maxn], nxt[maxn];

void get_nxt(int len){
    int k = -1; nxt[0] = -1;
    for(int i = 1; i < len; i++){
        while(k >= 0 && s[i] != s[k+1]) k = nxt[k];
        if(s[i] == s[k+1]) k++;
        nxt[i] = k;
    }
}
int match(int slen, int len){
    int k = -1, ans = 0;
    for(int i = 0; i < len; i++){
        while(k >= 0 && t[i] != s[k+1]) k = nxt[k];
        if(t[i] == s[k+1]) k++;
        if(k == slen-1) ans++;
    }
    return ans;
}

int n, m, p, a[maxn], b[maxn];

void DEBUG(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++) sc(s[i]);
        for(int i = 0; i < m; i++) sc(t[i]);
        get_nxt(n);
        printf("%d\n", match(n,m));
    }
}

int main(){
    //DEBUG();
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); sc(m); sc(p);
        for(int i = 1; i <= n; i++) sc(a[i]);
        for(int i = 0; i < m; i++) sc(s[i]);
        s[m] = -1;
        get_nxt(m);
        int ans = 0;
        for(int i = 1; i <= p; i++){
            int len = 0;
            for(int j = i; j <= n; j += p)
                t[len++] = a[j];
            ans += match(m,len);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
