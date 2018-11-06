include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;

int main(){
    int T; cin >> T;
    for(int kase=1;kase<=T;kase++){
        int n; sc(n);
        int now=2, ans=0;
        for(int i=1;i<=n;i++){
            if(now==1) ans++;
            now <<= 1;
            now %= 7;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
