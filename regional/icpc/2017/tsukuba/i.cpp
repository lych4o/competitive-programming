#include<bits/stdc++.h>
#define F first
#define S second
#define mk make_pair
//#define pair<int,int> pii
#define sc(x) scanf("%d",&x)
using namespace std;
const int maxn = 2e5+10;
struct pnt{
	int l,r,id;
	pnt(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const pnt& rr) const{
		if(l!=rr.l) return l > rr.l;
		return r < rr.r;
	}
	bool operator == (const pnt& rr) const{
		return l==rr.l && r==rr.r;
	}
} a[maxn];
int cnt[maxn], n, bit[maxn];
void add(int x, int v){for(int i=x;i<maxn;i+=i&-i) bit[i]+=v;}
int sum(int x){
	int ret=0;
	for(int i=x;i>0;i-=i&-i) ret+=bit[i];
	return ret;
}
int main(){
	sc(n);
	for(int i=0;i<n;i++){
		sc(a[i].l); sc(a[i].r);
		cnt[a[i].l]++; cnt[a[i].r]--;
		a[i].id=i;
	}
	int mn=n, tmp=0, now=0;
	for(int i=0;i<maxn;i++){
		now += cnt[i];
		tmp=max(tmp,now);
		//printf("now:%d\n",now);
	}
	mn=tmp;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++) add(a[i].l,1);
	for(int i=0;i<n;i++) cnt[i] += sum(a[i].r-1)-sum(a[i].l-1);
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++) add(a[i].r,1);
	for(int i=0;i<n;i++) cnt[i] += sum(a[i].r)-sum(a[i].l);
	memset(bit,0,sizeof(bit));
	sort(a,a+n);
	for(int i=0,j;i<n;i=j){
		j=i+1;
		while(j<n && a[j]==a[i]) j++;
		add(a[i].r, j-i);
		int s = sum(a[i].r)-sum(a[i].l);
		for(int fk=i;fk<j;fk++) cnt[a[fk].id] -= s;
		//printf("cnt[%d]:%d\n",a[i].id,cnt[a[i].id]);
	}
	int mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,cnt[i]);
	}
	printf("%d %d\n", mx, mn);
	return 0;
}
