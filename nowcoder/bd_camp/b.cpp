#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e6+10;

int n, a[maxn], f[maxn], ps[maxn];
int main(){
    int T; sc(T);
    while(T--){
        sc(n); 
        for(int i=1;i<=n;i++){
            int tmp; sc(tmp);
            f[tmp]=i;
        }
        for(int i=1;i<=n;i++) a[i]=f[i], ps[a[i]]=i;
        //for(int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
        int cnt=0;
        for(int i=1;i<n;i++){
            if((ps[i]-ps[i+1])%2==0) cnt++;
        }
        if(cnt<=1) puts("Yes");
        else puts("No");
    }   
    return 0;
}
