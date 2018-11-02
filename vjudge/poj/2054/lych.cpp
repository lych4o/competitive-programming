#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define sc(x) scanf("%d", &x)
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define pii pair<int,int>
#define mk make_pair
#define F first
#define S second
using namespace std;
const int maxn = 1e3+10;
int nxt[maxn], ed[maxn], fa[maxn],
	f[maxn], sz[maxn], val[maxn], c[maxn];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
void join(int x, int y){
	int fx=Find(x), fy=Find(y);
	f[fy]=fx;
	nxt[ed[fx]]=fy; ed[fx]=ed[fy];
	sz[fx]+=sz[fy]; val[fx]+=val[fy];
}
vector<int> to[maxn];
int n, rt;
void init(){
	for(int i=0;i<n+10;i++){
		to[i].clear(); sz[i]=1;
		f[i]=nxt[i]=ed[i]=i;
	}
}

int main(){
	while(scanf("%d%d",&n,&rt)!=EOF && n && rt){
		init();
        for(int i=1;i<=n;i++){
			sc(val[i]); c[i] = val[i];
        }
        for(int i=1;i<n;i++){
			int u,v; sc(u); sc(v);
			fa[v]=u; to[u].pb(v);
        }
		for(int t=1;t<n;t++){
			int nume=0,deno=1,pos;
			for(int i=1;i<=n;i++) if(i!=rt&&i==Find(i)){
				if(val[i]*deno>sz[i]*nume){
					pos = i;
					deno = sz[i];
					nume = val[i];
				}
			}
			int y=pos, x=fa[y];
			//printf("x:%d\n", x);
			join(x,y);
		}
        int ans = 0;
        for(int i=1,u=rt;i<=n;i++,u=nxt[u]){
			ans += i*c[u];
        }
        printf("%d\n", ans);
	}
	return 0;
}

