#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define pb push_back
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 1e3+10;
char s[maxn], res[maxn], us[maxn], zero[maxn];
int deal_zero(char* a){
    int len = strlen(a), p = 0;
    for(int i = 0; i < len; i++){
        if(a[i]=='0' && !p) continue;
        us[p++] = a[i];
    }
    for(int i = 0; i < p; i++) a[i] = us[i];
    a[p] = '\0';
    return p;
}
int sub(char* a, char* b, char* ret){
    int len = strlen(a), p = 0;
    for(int i = 0; i < len; i++) us[i] = a[i]-b[i]+'0';
    for(int i = len-1; i >= 0; i--){
        if(us[i] < '0') us[i] += 10, us[i-1]--;
    }
    for(int i = 0; i < len; i++){
        if(us[i] == '0' && !p) continue;
        ret[p++] = us[i];
    }
    if(p == 0) ret[p++] = '0';
    ret[p] = '\0';
    return p;
}
///cmp(a,b)=1 ,a>b,  = 0, ==,  = -1, a < b;
int cmp(char* a, char* b){
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    return 0;
}
char ans[60][maxn];

int main(){
    zero[0] = '0'; zero[1] = '\0';
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        scanf("%s", s);
        int cnt = 0;
        while(1){
            int n = strlen(s);
            for(int i = 0; i < n; i++) ans[cnt][i] = '0';
            ans[cnt][n] = '\0';
            for(int i = 0; i < (n+1)/2; i++){
                ans[cnt][i] = ans[cnt][n-i-1] = s[i];
                if(cmp(s,ans[cnt]) < 0){
                    ans[cnt][i]--; ans[cnt][n-i-1] = ans[cnt][i];
                    if(i == 0 && s[i]=='1'){
                        ans[cnt][n-1] = '1';
                    }
                    break;
                }
            }
            int len = sub(s, ans[cnt], res);
            //printf("%s - %s = %s\n",s,ans[cnt],res);
            for(int i = 0; i <= len; i++) s[i] = res[i];
            cnt++;
            if(cmp(s,zero) == 0) break;
        }
        printf("Case #%d:\n%d\n", kase,cnt);
        for(int i = 0; i < cnt; i++){
            deal_zero(ans[i]);
            printf("%s\n", ans[i]);
        }
    }
    return 0;
}
