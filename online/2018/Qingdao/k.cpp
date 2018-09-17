#include<iostream>
#include<cstdio>
#include<vector>
#define sc(x) scanf("%d", &x)
#define pb push_back

using namespace std;

const int maxn = 1e5+10;
int n, a[maxn], cnt[30];

int main(){
    int T; sc(T);
    while(T--){
        sc(n);        
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++){
            sc(a[i]);
            for(int j = 30; j >= 0; j--)
                if((a[i]>>j) > 0){
                    cnt[j]++;
                    break;
                }
        }
        int mx = 0;
        for(int i = 0; i < 30; i++){
            mx = max(mx, cnt[i]);
            //printf("cnt[%d]:%d\n",i,cnt[i]);
        }
        cout << mx << endl;
    }
    return 0;
}
