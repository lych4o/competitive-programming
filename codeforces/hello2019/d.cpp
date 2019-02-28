#include<bits/stdc++.h>
#define debug puts("???");fout
#define fout fflush(stdout)
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%I64d",&x)
#define F first
#define sz(x) ((int)x.size())
#define S second
#define mk make_pair
#define ALL(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxn = 1e4+10;
const int maxp = 52;

LL qpow(LL x, LL k){
    LL ret = 1;
    while(k>0){
        if(k&1) ret = ret*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return ret;
}
LL n, K;
LL p[maxp][2][maxp], s[maxp][2][maxp], pre, nxt, use,
   ans, vec[maxn], pw[maxn], tot=0, iv[maxp+1];
void add(LL& x, LL y){
    x = (x+y)>=mod?(x+y-mod):x+y;
}
void dfs(int ps, LL po, LL x){
    //printf("%d, %lld, %lld\n",ps,po,x); fout;
    if(ps==tot){
        add(ans, x%mod*po%mod);
        return;
    }
    LL nxt = x;
    for(int i=0;i<=pw[ps];i++){
        LL np = po*p[i][pre][pw[ps]]%mod;
        dfs(ps+1, np, nxt);
        nxt *= vec[ps];
    }
}
int main(){
    cin >> n >> K;
    //debug;
    for(int i=1;i<=maxp;i++) iv[i] = qpow(i,mod-2);
    for(int i=0;i<maxp;i++){
        //printf("i:%d\n",i); fout;
        pre = 0; nxt = 1;
        for(int j=i;j<maxp;j++){
            s[i][pre][j] = 1;
            p[i][pre][j] = (i==j);
        }
        for(int j=1;j<=K;j++){
            memset(s[i][nxt],0,sizeof(s[i][nxt]));
            memset(p[i][nxt],0,sizeof(p[i][nxt]));
            for(int k=i;k<maxp;k++){
                //printf("s[0][1][0]:%lld\n",s[0][1][0]);
                p[i][nxt][k] = s[i][pre][k];
                //printf("s[%d][%d][%d]:%lld\n",
                 //       i,j-1,k,s[i][j-1][k]);
                if(i>0) add(p[i][nxt][k], mod-s[i][pre][i-1]);
                p[i][nxt][k] = p[i][nxt][k]*iv[k+1]%mod;
                if(k>0) s[i][nxt][k] = (p[i][nxt][k] + s[i][nxt][k-1])%mod;
                else s[i][nxt][k] = p[i][nxt][k];
                if(p[i][nxt][k]<0||s[i][nxt][k]<0) puts("fuck");
                //printf("p[%d->%d][%d]:%lld\n",k,i,j,p[i][j][k]); fout;
            }
            swap(pre, nxt);
        }
    }
    /*for(int i=1;i<60;i++) for(int j=0;j<=i;j++){
        p[i][j][0] = (i==j);
        for(int h=1;h<maxn;h++){
            p[i][j][h] = 0;
            for(int l=j;l<=i;l++){
                add(p[i][j][h], p[l][j][h-1]*qpow((i+1),mod-2);
            }
        }
    }*/
    LL tmp = n;
    for(LL i=2;i*i<=tmp;i++){
        if((tmp%i)!=0) continue;
        //printf("tmp:%lld, i:%lld\n",tmp,i);
        LL cnt=0;
        while(tmp%i==0){
            tmp /= i;
            cnt++;
        }
        //printf("i:%lld, cnt:%lld, tmp:%lld\n",i,cnt,tmp); fout;
        vec[tot] = i; pw[tot++] = cnt;
    }
    if(tmp>1) pw[tot]=1, vec[tot++] = tmp;
    //for(int i=0;i<tot;i++) printf("(%lld,%lld)\n",vec[i],pw[i]); fout;
    dfs(0,1,1);
    cout << ans << endl;
    return 0;
}
