#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;

LL bit[maxn];
void add(int x, LL v){
	for(int i=x;i<maxn;i+=i&-i)
		bit[i] += v;
}
LL sum(int x){
	LL ret = 0;
	for(int i=x;i>0;i-=i&-i)
		ret += bit[i];
	return ret;
}
int n;
LL m, a[maxn], v[maxn], cnt;

int main(){
	sc(n); sll(m);
	cnt = n;
	for(int i=1;i<=n;i++){
		sll(a[i]); add(i,a[i]);
	}
	LL ans = 0, tot=sum(n);
	while(1){
		//printf("ans:%lld, tot:%lld\n",ans,tot);
		if(tot==0) break;
		ans += m/tot*cnt;
		m %= tot;
		int p=0;
		while(m < tot){
			int L=p,R=n;
			while(L+1<R){
                int mid=(L+R)>>1;
                if(sum(mid)>m) R=mid;
                else L=mid;
			}
			cnt--; add(R,-a[R]); tot-=a[R];
		}
	}
	cout << ans << endl;
	return 0;
}
