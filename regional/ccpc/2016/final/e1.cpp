#include<bits/stdc++.h>
#define N 100010
using namespace std;
 
priority_queue<int,vector<int>,greater<int> > q;
struct seg{int l,r;} a[N];
int b[N],n,m,ans;
 
bool cmp(seg a,seg b)
{
	return a.l==b.l?a.r>b.r:a.l<b.l;
}
 
int main()
{
	int T_T,T=0;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
        int j=1; ans=0;
		sort(b+1,b+1+m);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			while(j<=n&&a[j].l<=b[i]){q.push(a[j].r);j++;}
			while(!q.empty()&&q.top()<b[i]) q.pop();
			ans=max(ans,n-(int)q.size()+1); if (ans>n) break; q.pop();
			printf("c[%d]:%d, q.size():%d\n",i,b[i],q.size());
			//最后一个pop相当于是给每一个题目在题库中确定一个问题，因为这是一一对应的
		}
		if (ans>n) printf("Case #%d: IMPOSSIBLE!\n",++T,ans);
              else printf("Case #%d: %d\n",++T,ans);
	}
	return 0;
}
