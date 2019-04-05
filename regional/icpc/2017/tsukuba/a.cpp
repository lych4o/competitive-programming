#include<bits/stdc++.h>

using namespace std;

const int maxn=110;

int l,k;
long long f[maxn][2];

int main()
{
	scanf("%d%d",&l,&k);
	f[0][0]=1;
	for(int i=1;i<=l;i++)
	{
		f[i][0]+=f[i-1][1];
		f[i][1]+=f[i-1][0];
		if(i>=k)f[i][1]+=f[i-k][0];
	}

	long long ans=0;
	for(int i=1;i<=l;i++)
		ans+=f[i][1];

	printf("%lld",ans);

	return 0;
}
