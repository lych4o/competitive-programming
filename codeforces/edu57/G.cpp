#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int mod = 998244353, G = 3;
const int maxn = 3e6+10;

inline LL qpow(LL x, LL k){
	LL ret=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ret=ret*x%mod;
	return ret;
}
/************NTT*****************/
LL wn[30];
void getwn(){ //  千万不要忘记
    for (int i = 0; i <= 20; i++) wn[i] = qpow(G, (mod - 1) / (1 << i));
}
void ntt(LL y[], int len, int on=1){
    for (int i = 1, j = (len>>1); i < len - 1; i++){
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
    for (int h = 2, id = 1; h <= len; h <<= 1, id++){
        for (int j = 0; j < len; j += h){ 
            LL w = 1;
            for (int k = j; k < j + h / 2; k++){//记得对原数组取模
                LL u = y[k], t = w * y[k + h / 2] % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) + 2*mod) % mod;
                w = w * wn[id] % mod;
            }
        }
    }
    if (on == -1){
        //  原本的除法要用逆元
        LL inv = qpow(len, mod - 2);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = y[i] * inv % mod;
    }
}
/**************NTT**************/
int n, k;
LL a[maxn];
int main(){
	getwn();
	sc(n); sc(k);
	n /= 2;
	for(int i=0;i<k;i++){
		int tmp; sc(tmp);
		a[tmp]=1;
	}
	//int len = 32;
	int len = (1<<20);
	ntt(a,len);
	for(int i=0;i<len;i++){
		a[i]=qpow(a[i],n);
	}
	ntt(a,len,-1);
	//for(int i=0;i<30;i++) printf("a[%d]:%I64d\n",i,a[i]);
	LL ans=0;
	for(int i=0;i<len;i++) ans=(ans+a[i]*a[i])%mod;
	cout << ans << endl;
	return 0;
}
