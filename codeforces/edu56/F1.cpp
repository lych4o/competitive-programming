#include<cstdio>
const int N=100010,M=105,P=998244353;
int n,k,len,i,j,x,f[N][M],g[M],pre[N];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
int main(){
  scanf("%d%d%d",&n,&k,&len);
  if(len==1)return puts("0"),0;
  f[0][0]=pre[0]=1;
  for(j=1;j<=k;j++)g[j]=N;
  for(i=1;i<=n;i++){
    scanf("%d",&x);
    if(x!=-1){
      for(j=1;j<=k;j++)if(j!=x)g[j]=N;
      g[x]=g[x]<N?g[x]:i;
    }else{
      for(j=1;j<=k;j++)g[j]=g[j]<N?g[j]:i;
    }
    if(x==-1){
      f[i][0]=1LL*pre[i-1]*k%P;
      for(j=1;j<=k;j++)if(g[j]<=i-len+1){
        f[i][j]=P-pre[i-len];
        up(f[i][j],P-f[i-1][j]);
        up(f[i][j],f[i-len][j]);
      }
    }else{
      f[i][0]=pre[i-1];
      if(g[x]<=i-len+1){
        f[i][x]=P-pre[i-len];
        up(f[i][x],P-f[i-1][x]);
        up(f[i][x],f[i-len][x]);
      }
    }
    pre[i]=f[i][0];
    for(j=1;j<=k;j++){
      up(pre[i],f[i][j]);
      up(f[i][j],f[i-1][j]);
      printf("f[%d][%d]:%d\n",i,j,f[i][j]);
    }
    printf("pre[%d]:%d, f[%d][0]:%d\n",i,pre[i],i,f[i][0]);
  }
  printf("%d",(pre[n]%P+P)%P);
}
