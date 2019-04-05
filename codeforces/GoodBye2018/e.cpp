#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
typedef double db;
const LL mod = 1e9+7;
const int maxn = 1e6+10;

int n;
LL a[maxn], cnt[maxn];

int check(LL x){
	printf("check(%lld)\n",x);
	LL L=0,R=0,les=0;
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	cnt[x]++;
	for(int i=1,j=1;i<=n+1;i++){
		LL v = (i==j&&(i==n+1||a[j]<x))?x:a[j++];
		L += v; cnt[v]--; 
		if(v<i-1) les--;
		les += cnt[i-1];
		R -= min(v, i-1LL);
		R += n+1-i-les;
		printf("k:%d, L:%lld, R:%lld, les:%lld\n",i,L,R,les);
		if(L>R+1LL*i*(i-1)){
			return (i==j)?1:-1;
		}
	}
	return 0;
}
int main(){
	while(sc(n)!=EOF){
		LL s=0;
		for(int i=1;i<=n;i++) scanf("%I64d",&a[i]), s+=a[i];
		s &= 1;
		sort(a+1,a+n+1,greater<LL>());
		for(int i=0;i<=n;i++) printf("%d ",check(i));
		puts("");
	}
	return 0;
}
