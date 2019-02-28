#include<bits/stdc++.h>
using namespace std;

const int maxn = 505;
char a[maxn][maxn];
int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++) scanf("%s",a[i]);
    int cnt=0;
    for(int i=1;i+1<n;i++) for(int j=1;j+1<n;j++){
        if(a[i][j]=='X'&&a[i-1][j-1]=='X'&&
           a[i-1][j+1]=='X'&&a[i+1][j-1]=='X'&&
           a[i+1][j+1]=='X') cnt++;
    }
    cout << cnt << endl;
    return 0;
}
