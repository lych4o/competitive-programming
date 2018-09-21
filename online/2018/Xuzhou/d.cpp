#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
#define ln puts("")
#define sp putchar(' ')
#define debug printf("???\n");fflush(stdout)
#define fout fflush(stdout)
using namespace std;
typedef long long LL;
//const LL mod = 1e9+7;
const int maxn = 1e6+10;
LL p[maxn], pnum, nop[maxn];
void prime_sieve(){
    for(int i = 2; i < maxn; i++){
        if(!nop[i]) p[++pnum] = i;
        for(int j = 1; p[j]*i < maxn; j++){
            nop[p[j]*i] = 1;
            if(i%p[j] == 0) break;
        }
    }
}
/*
LL qpow(LL x, LL k){
    LL res = 1;
    while(k > 0){
        if(k&1) res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}*/
LL g[2][maxn], h[2][maxn], nn, n, iv2, m;
LL mp[40], mpnum=0;
inline LL get(LL func[2][maxn], LL idx){
    if(idx <= nn) return func[0][idx];
    return func[1][n/idx];
}
inline LL ff1(LL x){ return 1;}
inline LL sum1(LL x){ return x;}//return x%mod;}
inline void _add(LL& a, LL b){
    //a = (a+b)>=mod?a+b-mod:a+b;
    a = a+b;
}
inline void _sub(LL& a, LL b){
    //a = (a-b)<0?a-b+mod:a-b;
    a = a-b;
}
void calc(){
    for(int i = 1; i <= nn; i++){
        g[0][i] = sum1(i)-1, g[1][i] = sum1(n/i)-1;
    }
    for(int j = 1; j <= pnum; j++){
        for(int i = 1; i <= nn && n >= 1LL*i*p[j]*p[j]; i++){
            //_sub(g[1][i], ff1(p[j])*(get(g, n/i/p[j])-get(g,p[j-1]))%mod);
            _sub(g[1][i], ff1(p[j])*(get(g, n/i/p[j])-get(g,p[j-1])));
        }
        for(int i = nn; i >= 1 && i >= 1LL*p[j]*p[j]; i--){
            //_sub(g[0][i], ff1(p[j])*(get(g, i/p[j])-get(g,p[j-1]))%mod);
            _sub(g[0][i], ff1(p[j])*(get(g, i/p[j])-get(g,p[j-1])));
        }
    }
    
    for(LL i = 1; i <= nn; i++){
        int j=0;
        for(j=0; mp[j]<=i && j<mpnum; j++);
        _sub(g[0][i], j); //printf("j:%d\n",j);
        for(j=0; mp[j]<=n/i && j<mpnum; j++);
        _sub(g[1][i], j); //printf("j:%d\n",j);
        //printf("g[%lld]:%lld, g[%lld]:%lld\n",i,g[0][i],n/i,g[1][i]); fout;
    }
}
inline LL f(LL prime, LL k){
    if((m%prime) == 0 || k > 1) return 0;
    return -1;
}
LL ask(LL a, int b){
    if(a < p[b]) return 0;
    LL ret = -get(g,a)+get(g,p[b]-1);
    //printf("s(%lld, %d):%lld\n",a,b,ret);
    if(n < 1LL*p[b]*p[b]) return ret;
    for(int j = b; j<=pnum && 1LL*p[j]*p[j]<=a; j++){
        for(LL pp = p[j], k=1; p[j]*pp <= a; k++, pp *= p[j]){
            //_add(ret, ask(a/pp,j+1)*f(p[j],k)%mod);
            _add(ret, ask(a/pp,j+1)*f(p[j],k));//%mod);
            _add(ret, f(p[j],k+1));
        }
    }
    //printf("s(%lld, %d):%lld\n",a,b,ret);
    return ret;
}

int main(){
    prime_sieve();
    cin >> n >> m;
    LL tmp = m, miu = 1;
    for(LL i = 2; i*i <= tmp; i++){
        //printf("i:%lld\n",i);fout;
        if(tmp%i) continue;
        int cnt = 0;
        mp[mpnum++] = i;
        while((tmp%i)==0) tmp/=i, cnt++;
        if(cnt>1) miu *= 0;
        else miu *= -1;
    }
    if(tmp>1) mp[mpnum++] = tmp, miu *= -1;
    //for(int i = 0; i < mpnum; i++) printf("%lld ",mp[i]), fout; ln;
    nn = (LL)sqrt(n); 
    calc();
    //cout << miu*(ask(n, 1)+1+mod)%mod << endl;
    cout << miu*(ask(n, 1)+1) << endl;
    return 0;
}
