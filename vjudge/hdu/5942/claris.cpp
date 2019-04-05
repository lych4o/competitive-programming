#include<cstdio>
typedef long long ll;
const int N=1000010,P=1000000007;
int T,C,tot,p[N/10],i,j,ans,f[N];char mu[N],v[N];ll n;
inline int F(ll n){
  if(n<N)if(f[n])return f[n];
  ll t=0;
  for(ll i=1,j;i<=n;i=j+1)j=n/(n/i),t+=n/i*(j-i+1);
  t%=P;
  if(n<N)f[n]=t;
  return t;
}
int main(){
  for(mu[1]=1,i=2;i<N;i++){
    if(!v[i])mu[i]=-1,p[tot++]=i;
    for(j=0;j<tot&&i*p[j]<N;j++){
      v[i*p[j]]=1;
      if(i%p[j])mu[i*p[j]]=-mu[i];else break;
    }
  }
  for(scanf("%d",&T);T--;printf("Case #%d: %d\n",++C,(ans+P)%P)){
    scanf("%I64d",&n);
    for(ans=0,i=1;i<=n/i;i++)if(mu[i])ans=(ans+F(n/i/i)*mu[i])%P;
  }
  return 0;
}
