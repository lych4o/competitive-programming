#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define maxn 8
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxm = 1e5+10;

int n, mu[maxn], q;
bitset<maxn> b[maxn], c[maxn], a[maxm], f[maxn];
int main(){
    for(int i=maxn-1;i>0;i--){
        f[i][i]=1;
        for(int j=2*i;j<maxn;j+=i){
            f[i]^=f[j];
        }
        cout << "f["<<i<<"]:"<<f[i]<<endl;
    }
    for(int i=1;i<maxn;i++){
        mu[i] = (i==1)-mu[i];
        for(int j=i*2;j<maxn;j+=i){
            mu[j] += mu[i];
        }
        //printf("mu[%d]:%d\n",i,mu[i]);
    }
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            b[j][i]=1; c[i][j]=(mu[j/i])?1:0;
        }
    }
    sc(n); sc(q);
    string ans="";
    while(q--){
        int op,x,y,z; sc(op);
        if(op==1){
            sc(x); sc(y);
            a[x] = b[y];
            //cout << a[x] << endl;
        }else if(op==2){
            sc(x); sc(y); sc(z);
            a[x] = a[y]^a[z];
            //cout << a[x] << endl;
        }else if(op==3){
            sc(x); sc(y); sc(z);
            a[x] = a[y]&a[z];
            //cout << a[x] << endl;
        }else{
            sc(x); sc(y);
            bitset<maxn> bs = a[x]&c[y];
            if(bs.count()&1) putchar('1');
            else putchar('0');
        }
    }
    cout << ans << endl;
    return 0;
}
