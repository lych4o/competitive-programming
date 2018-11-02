#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define sc(x) scanf("%d",&x)
using namespace std;
 
struct dd{
    int y,m,d;
    dd(int y=0,int m=0,int d=0):y(y),m(m),d(d){}
    bool operator < (const dd& rhs) const{
        if(y!=rhs.y) return y<rhs.y;
        if(m!=rhs.m) return m<rhs.m;
        return d<rhs.d;
    }
    dd nxt(){
        int up=0;
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) up = 31;
        else if(m!=2) up=30;
        else{
            int flg=0;
            if(y%400==0) flg=1;
            else if(y%100==0) flg=0;
            else if(y%4==0) flg=1;
            up = flg?29:28;
        }
        if(d < up) return dd(y,m,d+1);
        else if(m < 12) return dd(y,m+1,1);
        else return dd(y+1,1,1);
    }
    int check(){
        string s;
        s += y/1000 + '0';
        s += (y/100)%10 + '0';
        s += (y/10)%10 + '0';
        s += y%10 + '0';
        s += m/10 + '0';
        s += m%10 + '0';
        s += d/10 + '0';
        s += d%10 + '0';
        for(int i=0;i<SZ(s);i++){
            int j = SZ(s)-i-1; if(j<i) return 1;
            if(s[i]!=s[j]) return 0;
        }
        return 1;
    }
};
int main(){
    int T; sc(T);
    while(T--){
        dd L, R;
        int y0,m0,d0,y1,m1,d1;
        scanf("%d-%d-%d",&y0,&m0,&d0);
        scanf("%d-%d-%d",&y1,&m1,&d1);
        L=dd(y0,m0,d0); R=dd(y1,m1,d1);
        dd now = L;
        int ans = 0;
        while(now<R){
            ans += now.check();
            now = now.nxt();
        }
        ans += R.check();
        printf("%d\n",ans);
    }
    return 0;
}
