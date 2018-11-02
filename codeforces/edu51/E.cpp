#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL mod = 998244353;
const int maxn = 2e6+10;
char L[maxn],R[maxn],s[maxn];
int nL[maxn], nR[maxn], exL[maxn], exR[maxn];
void get_nxt(char* s, int* nxt){
    int n = (nxt[0]=strlen(s)), p=1; nxt[1]=0;
    while(nxt[1]+1<n && s[nxt[1]+1]==s[nxt[1]]) nxt[1]++;
    for(int i=2; i<n; i++){
        if(nxt[i-p]+i < nxt[p]+p) nxt[i]=nxt[i-p];
        else{
            int j=max(0,nxt[p]+p-i);
            while(i+j<n && s[i+j]==s[j]) j++;
            nxt[i]=j, p=i;
        }
    }
}
void get_ex(char* s, int* nxt, char* t, int* ex){
    int n=strlen(s), m=strlen(t), p=1; ex[0]=0;
    while(ex[0]<m && ex[0]<n && s[ex[0]]==t[ex[0]]) ex[0]++;
    for(int i=1; i<m; i++){
        if(nxt[i-p]+i < ex[p]+p) ex[i]=nxt[i-p];
        else{
            int j=max(0, ex[p]+p-i);
            while(i+j<m && j<n && t[i+j]==s[j]) j++;
            ex[i]=j, p=i;
        }
    }
}

LL add[maxn], dp[maxn];

int main(){
    scanf("%s%s%s", s,L,R);
    get_nxt(L,nL); get_nxt(R,nR);
    get_ex(L,nL,s,exL); get_ex(R,nR,s,exR);
    int n=strlen(s), x=strlen(L), y=strlen(R),f1=(L[0]=='0');
    LL now = 0; add[0]=1; add[1]=-1;
    for(int i = 0; i < n; i++){
        now = (add[i]+now)%mod;
        dp[i] = now;
        if(s[i]=='0'){
            if(f1){
                add[i+1]+=dp[i]; add[i+1] %= mod;
                add[i+2]-=dp[i]; add[i+2] %= mod;
            }
            continue;
        }
        //printf("dp[%d]:%lld\n",i,dp[i]);
        int p1=exL[i],p2=exR[i];
        //printf("i:%d, (%d,%d)",i,p1,p2);
        if(p1<x&&i+p1<n&&L[p1]>s[i+p1]) p1=x+1;
        else p1=x;
        if(p2<y&&i+p2<n&&R[p2]<s[i+p2]) p2=y-1;
        else p2=y;
        //printf("p2:%d  ", p2);
        p1 = i+p1, p2 = i+p2+1;
        add[p1] += dp[i]; add[p2] -= dp[i];
        add[p1] %= mod; add[p2] %= mod;
        //printf("-->[%d,%d)\n",p1,p2);
    }
    //cout << add[n] << endl;
    cout << ((now+add[n])%mod+mod)%mod << endl;
    //cout << (now%mod+mod)%mod << endl;
    return 0;
}
