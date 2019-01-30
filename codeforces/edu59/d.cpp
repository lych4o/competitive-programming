#include<bits/stdc++.h>
using namespace std;
const int maxn = 5212;
int n;
bool a[maxn][maxn];
char s[maxn];
int gcd(int a, int b){
    if(!a) return b;
    return gcd(b%a, a);
}
inline int id(char c){
    if(c>='0' && c<='9') return c-'0';
    return c-'A'+10;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;j<n;j+=4){
            int x = id(s[j/4]);
            a[i][j]=(x>>3)&1; a[i][j+1]=(x>>2)&1;
            a[i][j+2]=(x>>1)&1; a[i][j+3]=x&1;
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",a[i][j]);
        }
        puts("");
    }*/
    int ans = n;
    for(int i=0;i<n;i++){
        for(int l=0,r;l<n;l=r){
            for(r=l;a[i][r]==a[i][l] && r<n;r++);
            //printf("a[%d][%d-%d]\n",i,l,r);
            ans = gcd(ans, r-l);
        }
        for(int l=0,r;l<n;l=r){
            for(r=l;a[r][i]==a[l][i] && r<n;r++);
            //printf("a[%d-%d][%d]\n",l,r,i);
            ans = gcd(ans, r-l);
        }
    }
    cout << ans << endl;
    return 0;
}
