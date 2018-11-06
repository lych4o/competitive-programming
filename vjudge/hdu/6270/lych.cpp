#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define F first
#define S second
#define mk make_pair
using namespace std;
typedef long long LL;
const int mod = 998244353, G = 3;
const int maxn = 2e5+10;
LL qpow(LL x, LL k){
	LL ret=1;
	while(k>0){
		if(k&1) ret=ret*x%mod;
		k>>=1; x=x*x%mod;
	}
	return ret;
}

/*****comb**********/
const int maxc=1e6+10;
int FAC[maxc],IVF[maxc],IV[maxc];
void init(){
	IV[1]=FAC[0]=FAC[1]=IVF[0]=IVF[1]=1;
	for(int i=2;i<maxc;i++){
		FAC[i]=1LL*FAC[i-1]*i%mod;
		IV[i]=1LL*(mod-mod/i)*IV[mod%i]%mod;
		IVF[i]=1LL*IVF[i-1]*IV[i]%mod;
	}
}
inline LL C(int x, int y){return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;}
/********comb***********/
/****************NTT****************/
LL wn[20];
void getwn(){for(int i=0;i<20;i++) wn[i]=qpow(G,(mod-1)/(1<<i));}
void ntt(vector<LL>& y, int len, int on=1){
	y.resize(len);
	for(int i=1,j=(len>>1);i<len-1;i++){
		if(i<j) swap(y[i],y[j]);
		int k=len/2;
		while(j>=k) j-=k, k>>=1;
		if(j<k) j+=k;
	}
	for(int h=2,id=1;h<=len;h<<=1,id++){
		for(int j=0;j<len;j+=h){
			LL w=1;
			for(int k=j;k<j+h/2;k++){
				LL u=y[k], t=w*y[k+h/2]%mod;
				y[k]=(u+t)%mod, y[k+h/2]=((u-t)+2*mod)%mod;
				w=w*wn[id]%mod;
			}
		}
	}
	if(on==-1){
		LL inv=qpow(len,mod-2);
		for(int i=1;i<len/2;i++) swap(y[i],y[len-i]);
		for(int i=0;i<len;i++) y[i]=y[i]*inv%mod;
	}
}/***********************NTT**********************/

int n, a[maxn], b[maxn], m;
vector<LL> f[maxn];
priority_queue<pii> pq;
void join(int x, int y){
	int len=1; while(len<SZ(f[x])+SZ(f[y])-1) len<<=1;
	ntt(f[x],len); ntt(f[y],len);
	for(int i=0;i<len;i++) f[x][i]=f[x][i]*f[y][i]%mod;
	ntt(f[x],len,-1);
	while(len>1 && f[x][len-1]==0) len--;
	f[x].resize(len);
}
int main(){
	init(); getwn();
	int T; sc(T);
	while(T--){
		while(SZ(pq)) pq.pop(); m=0;
        sc(n); for(int i=0;i<n;i++) sc(a[i]),sc(b[i]),f[i].resize(min(a[i],b[i])+1);
		for(int i=0;i<n;i++) for(int j=0;j<=min(a[i],b[i]);j++)
			f[i][j]=C(a[i],j)*C(b[i],j)%mod*FAC[j]%mod;
		/*for(int i=0;i<n;i++){
			for(int j=0;j<=min(a[i],b[i]);j++){
				printf("f[%d][%d]:%lld\n",i,j,f[i][j]);
			}
		}*/
		for(int i=0;i<n;i++) pq.push(mk(-SZ(f[i]),i)), m+=a[i];
		while(SZ(pq)>1){
			pii p1=pq.top(); pq.pop();
			pii p2=pq.top(); pq.pop();
			int u=p1.S, v=p2.S;
			join(u,v);
			pq.push(mk(-SZ(f[u]),u));
		}
		//printf("(%d,%d)\n", pq.top().F,pq.top().S);
		vector<LL> F = f[pq.top().S];
		LL ans=0;
		for(int i=0;i<SZ(F);i++){
			//printf("F[%d]:%lld\n", i,F[i]);
			int k=i%2?-1:1;
			ans += k*F[i]*FAC[m-i]%mod;
			ans %= mod;
		}
		printf("%lld\n", (ans%mod+mod)%mod);
	}
	return 0;
}

