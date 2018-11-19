#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define sll(x) scanf("%I64d", &x)
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pLL pair<LL,LL>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 1e6+10;

int n, vis[maxn];
char s[maxn];
int solve1(int m){
	char mn='z';
	int p=m-1;
	for(int i=0;i<m;i++){
		if(s[i]<=mn){
			mn=s[i];
			p=i;
		}
	}
	vis[p]=1;
	return p;
}
int solve2(int m){
	char mn='z';
	int p=m-1;
	for(int i=0;i<m;i++){
		if(s[i]<=mn){
			mn=s[i];
			p=i;
		}
	}
	if(p<m-1) vis[p]=vis[m-1]=1;
	return p;
}
int main(){
	scanf("%s", s); n=strlen(s);
	int p=solve1(n);
	while(p>1){
		p = solve2(p);
	}
	for(int i=0;i<n;i++) printf("%d ",vis[i]); puts("");
	return 0;
}
