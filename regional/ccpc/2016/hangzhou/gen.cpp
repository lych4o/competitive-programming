#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    printf("%d\n",(1<<n));
    for(int i=1;i<=(1<<n);i++){
        printf("%d %d\n",n,i);
    }
}
