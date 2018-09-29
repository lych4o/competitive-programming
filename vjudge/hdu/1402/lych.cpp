#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mod = 119 << 23 | 1;
const int G = 3;
int wn[20];

int qpow(int x, int k){
    int ret = 1;
    while(k > 0){
        if(k&1) ret = 1LL*ret*x%mod;
        x = 1LL*x*x%mod;
        k >>= 1;
    }
    return ret;
}
void getwn(){ //  千万不要忘记
    for (int i = 0; i < 20; i++) wn[i] = qpow(G, (mod - 1) / (1 << i));
}
void change(int y[], int len){
    for (int i = 1, j = (len>>1); i < len - 1; i++){
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k >>= 1;
        if (j < k) j += k;
    }
}
void ntt(int y[], int len, int on=1){
    change(y, len);
    for (int h = 2, id = 1; h <= len; h <<= 1, id++){
        for (int j = 0; j < len; j += h){
            int w = 1;
            for (int k = j; k < j + h / 2; k++){
                int u = y[k];
                int t = 1LL * w * y[k + h / 2] % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) + 2LL*mod) % mod;
                w = 1LL * w * wn[id] % mod;
            }
        }
    }
    if (on == -1){
        //  原本的除法要用逆元
        int inv = qpow(len, mod - 2);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = 1LL * y[i] * inv % mod;
    }
}

const int maxn = 5e4+10;
char s[maxn];
int a[maxn*4], b[maxn*4], n1, n2;

int main(){
    while(scanf("%s",s)!=EOF){
        n1 = strlen(s); 
        for(int i=0; i < n1; i++) a[n1-i-1]=s[i]-'0';
        scanf("%s", s); n2 = strlen(s);
        for(int i = 0; i < n2; i++) b[n2-i-1]=s[i]-'0';
        int len = 1; while(len < n1+n2) len <<= 1; 
        for(int i = n1; i < len; i++) a[i]=0;
        for(int i = n2; i < len; i++) b[i]=0;
        getwn(); ntt(a,len); ntt(b,len);
        for(int i = 0; i < len; i++) a[i]=1LL*a[i]*b[i]%mod;
        ntt(a,len,-1); 
        int ed = 0;
        for(int i = 0; i < len-1; i++){
            a[i+1] += a[i]/10;
            a[i] %= 10;
            if(a[i]>0) ed = i;
        }
        for(int i = ed; i >= 0; i--){
            printf("%d", a[i]);
        }puts("");
    }
    return 0;
}
