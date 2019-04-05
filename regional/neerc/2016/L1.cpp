#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
using namespace std;
const int maxn=1e6;
int isprime[maxn],p[maxn];
vector<int>primes;
vector<int>vec;
map<P,P>M;
ll a,b,cur,prefix_len;
int getL(int x){
    int res=0;
    while(x>0){ res++; x/=10;}
    return res+2;
}
inline P get(P p1,P p2,ll len){
    return P(p1.first+p2.first,p1.second+p2.second+len*p1.first); 
}
P calc(int x,int sum)
{
	//printf("calc(%d,%d)\n",x,sum);
    P p(x,sum);
    if(sum<0) return P(0,0);
    if(M.count(p)) return M[p];
    if(sum==0) return M[p]=P(1,2); //ct,len
    if(primes[x]>sum) return P(0,0);
    return M[p]=get(calc(x+1,sum-primes[x]),calc(x+1,sum),getL(primes[x]));
}
void ptchar(char c){
    cur++; if(cur>=a&&cur<=b) putchar(c);
}
void print(int x){
    vector<int>v;
    while(x>0){ v.push_back(x%10); x/=10;}
    for(int i=v.size()-1;i>=0;i--) ptchar(char(v[i]+'0'));
}
void print(int x,int sum)
{
    if(sum<0||cur>=b) return ;
    if(sum==0){
        ptchar('[');
        for(int i=0;i<vec.size();i++){
            print(vec[i]);
            if(i==vec.size()-1) ptchar(']');
            ptchar(',');
            ptchar(' ');
        } return ;
    }
    if(primes[x]>sum) return ;
    vec.push_back(primes[x]);
    prefix_len+=getL(primes[x]);
    ll len=prefix_len*calc(x+1,sum-primes[x]).first+calc(x+1,sum-primes[x]).second;
    if(len+cur>=a) print(x+1,sum-primes[x]);
    else cur+=len;
    
    vec.pop_back();
    prefix_len-=getL(primes[x]);
    len=prefix_len*calc(x+1,sum).first+calc(x+1,sum).second;
    if(len+cur>=a) print(x+1,sum);
    else cur+=len;
} 
void debug(){
	int x,y;
	while(cin >> x >> y){
		printf("(%lld,%lld)\n",calc(x,y).first,calc(x,y).second);
	}
}
int main()
{
    //freopen("list.in","r",stdin);
    //freopen("list.out","w",stdout);
    isprime[1]=false;
    fill(isprime,isprime+maxn,true);
    for(int i=2;i<maxn;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i+i;j<maxn;j+=i) isprime[j]=false;
        }
    }
	//debug();
	scanf("%I64d%I64d",&a,&b);
    for(int i=2;i<100000&&cur<b;i++){ //试探过，i最大到2096，这个范围的素数也就300来个，所以记忆化 
        ll len=calc(0,i).second;
        if(cur+len>=a) print(0,i);
        else cur+=len;
    }
    puts("");
    return 0;
}
