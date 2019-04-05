#include<bits/stdc++.h>

using namespace std;

int n,k;
int f[10086],sum[10086];
char st[100],ed[100];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",st);
	scanf("%s",ed);

	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if(ed[i]!=ed[i-1])sum[i]++;
	}

	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=1e9;
		for(int j=1;j<=k;j++)
			f[i]=min(f[i],f[i-j]+(sum[i]-sum[i-j])/2+1);
		if(st[i]==ed[i])f[i]=min(f[i],f[i-1]);
	}

	printf("%d",f[n]);

	return 0;
}
