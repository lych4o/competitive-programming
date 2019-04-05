#include<bits/stdc++.h>
#define fout fflush(stdout)
#define sc(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a, a);
}
const int maxn = 1e6+10;
int vis[maxn], n;
vector<int> v;

LL RAND(){
	return rand()*1LL*(RAND_MAX+1) + rand();
}
int main(){
	//cout << RAND_MAX << endl;
	srand(time(NULL));
	sc(n);
	/*if(n<=60){
		for(int i=1;i<=n;i++){
			printf("? %d\n",i); fout;
			int tmp; sc(tmp);
			v.push_back(tmp);
		}
		sort(v.begin(),v.end());
		printf("! %d %d\n", v[0], v[1]-v[0]);
		return 0;
	}*/
	for(int i=0;i<min(30,n);i++){
		int p = (RAND()%n) + 1;
		while(vis[p]) p = (RAND()%n) + 1;
		vis[p] = 1;
		printf("? %d\n", p); fout;
		int tmp; sc(tmp);
		v.push_back(tmp);
	}
	int d = abs(v[0]-v[1]);
	for(int i=0;i<min(30,n);i++) for(int j=0;j<min(30,n);j++){
		d = gcd(d, abs(v[i]-v[j]));
	}
	fout;
	//printf("d:%d\n",d);
	LL L=-1, R=1e9+10;
	while(L+1<R){
		LL mid = (L+R)>>1;
		LL x1 = mid, xn = x1 + (n-1)*1LL*d;
		//printf("L:%lld, R:%lld, x1:%lld, xn:%lld\n",L,R,x1,xn);
		if(xn > 1e9){ R=mid; continue;}
		printf("> %lld\n", xn); fout;
		int tmp; sc(tmp);
		if(tmp){
			//xxn < xn --> mid > x1
			L = mid;
		}else{
			//xxn
			R = mid;
		}
	}
	printf("! %lld %d\n", R, d); fout;
	return 0;
}
