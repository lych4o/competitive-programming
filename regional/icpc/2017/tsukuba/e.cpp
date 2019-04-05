#include<bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;

int n,k,l;
int sum[maxn];
double f[maxn],mno[maxn*4],mne[maxn*4];
char st[maxn],ed[maxn];

void update(int t,double val,double z[])
{
	z[t+=l-1]=val;
	for(t>>=1;t;t>>=1)
		z[t]=min(z[t<<1],z[(t<<1)+1]);
}

double getmin(int s,int r,double z[])
{
	double re=1e9;
	for(s+=l-1,r+=l-1;s<=r;s>>=1,r>>=1)
	{
		if(s&1)re=min(re,z[s]),s++;
		if(!(r&1))re=min(re,z[r]),r--;
	}
	return re;
}

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",st+1);
	scanf("%s",ed+1);

	for(l=1;l<n;l<<=1);
	for(int i=1;i<=l;i++)
		update(i,1e9,mno),update(i,1e9,mne);
	for(int i=2;i<=n+1;i++)
	{
		
		if(ed[i]!=ed[i-1])sum[i-1]++;
		sum[i]=sum[i-1];
	}

	update(1,0,mne);
	for(int i=1;i<=n;i++)
	{
		f[i]=1e9;
		if(sum[i-1]&1)
		{
			f[i]=min(f[i],getmin(max(i-k+1,1),i,mno));
			f[i]=min(f[i],getmin(max(i-k+1,1),i,mne)+0.5);
		}
		else
		{
			f[i]=min(f[i],getmin(max(i-k+1,1),i,mne));
			f[i]=min(f[i],getmin(max(i-k+1,1),i,mno)+0.5);
		}
		f[i]+=1+sum[i-1]/2.0;
		if(st[i]==ed[i])f[i]=min(f[i],f[i-1]);

		if(sum[i]&1)update(i+1,f[i]-sum[i]/2.0,mno);
		else update(i+1,f[i]-sum[i]/2.0,mne);
	}

	printf("%d",(int)f[n]);

	return 0;
}
