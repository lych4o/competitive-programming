#include<bits/stdc++.h>

using namespace std;

const int maxn=17;
const double eps=1e-9;

int n,tot,ans;
struct point{int x,y;}p[maxn];
int bj[maxn];
struct data{int dx,dy;}line[maxn],tmpp[maxn];

int gcd(int a,int b)
{
	while(b)a%=b,swap(a,b);
	return a;
}

bool cmp(data a,data b)
{
	if(a.dx==b.dx)return a.dy<b.dy;
	return a.dx<b.dx;
}

data getk(point a,point b)
{
	int dx = a.x - b.x, dy = a.y - b.y;
	if(!dx)dy=1;
	else if(!dy)dx=1;
	else 
	{
		if(dy<0)dx=-dx,dy=-dy;
		int tmp=gcd(abs(dx),abs(dy));
		dx/=tmp,dy/=tmp;
	}
	return (data){dx,dy};

}

void dfs(int t)
{
	if(t>n)
	{
		memcpy(tmpp,line,sizeof(line));
		sort(tmpp+1,tmpp+tot+1,cmp);
		int cnt=1,re=0;
		for(int i=2;i<=tot;i++)
		{
			if(tmpp[i].dx==tmpp[i-1].dx&&tmpp[i].dy==tmpp[i-1].dy)cnt++;
			else re+=cnt*(cnt-1)/2,cnt=1;
		}
		re+=cnt*(cnt-1)/2;
		ans=max(ans,re);
		return;
	}
	if(bj[t])
	{
		dfs(t+1);
		return;
	}

	bj[t]=1;
	for(int i=t+1;i<=n;i++)
		if(!bj[i])
		{
			line[++tot]=getk(p[i],p[t]);
			bj[i]=1;
			dfs(t+1);
			bj[i]=0;
			tot--;
		}
	bj[t]=0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);

	dfs(1);

	printf("%d",ans);

	return 0;
}
