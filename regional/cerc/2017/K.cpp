#include<bits/stdc++.h>
#define sc(x) scanf("%d", &x)
#define pb push_back
using namespace std;
const int maxn = 510;
string s;

int equ(){
    for(int i=0;i<7;i++){
        if(s[i]!=s[0]) return 0;
    }
    return 1;
}
int get(){
    string mx = s, tmp;
    int mxpos = 0;
    for(int i=0;i<7;i++){
        tmp = s.substr(i,7-i)+s.substr(0,i);
        if(tmp > mx){
            mxpos = i;
            mx = tmp;
        }
    }
    return mxpos;
}

struct pnt{
    int a,b,c,v;
    pnt(int a=0,int b=0,int c=0,int v=0):a(a),b(b),c(c),v(v){}
};
vector<pnt> vp;
int n, dp[maxn][maxn][maxn], pos[maxn], cnt[10];

int main(){
    sc(n);
    for(int i = 0; i < n; i++){
        cin >> s;
        if(equ()){
            n--, i--;
            continue;
        }
        pos[i] = get();
    }
    for(int i=1;i<=n;i++){
        cnt[(pos[i]-pos[i-1]+14)%7]++;
    }
    if(n) cnt[pos[0]]++;
    /*for(int i = 0; i < n; i++){
        printf("pos[%d]:%d\n",i,pos[i]);
    }
    for(int i=0;i<7;i++){
        printf("cnt[%d]:%d\n",i,cnt[i]);
    }*/
    int X,Y,Z,cX,cY,cZ, ans=0;
    while(cnt[1]&&cnt[6]) cnt[1]--,cnt[6]--,ans++;
    X = cnt[1]?1:6, cX = cnt[1]?cnt[1]:cnt[6];
    while(cnt[2]&&cnt[5]) cnt[2]--,cnt[5]--,ans++;
    Y = cnt[2]?2:5, cY = cnt[2]?cnt[2]:cnt[5];
    while(cnt[3]&&cnt[4]) cnt[3]--,cnt[4]--,ans++;
    Z = cnt[3]?3:4, cZ = cnt[3]?cnt[3]:cnt[4];
    for(int i=0;i<=7;i++)for(int j=0;j<=7;j++)for(int k=0;k<=7;k++){
        if((i+j+k) && (i*X+j*Y+k*Z)%7==0){
            vp.pb(pnt(i,j,k,i+j+k-1));
        }
    }
    for(int i=0;i<=cX;i++)for(int j=0;j<=cY;j++)for(int k=0;k<=cZ;k++){
        if(!(i+j+k)) continue;
        dp[i][j][k]=i+j+k;
        for(pnt p: vp){
            if(i>=p.a&&j>=p.b&&k>=p.c)
                dp[i][j][k]=min(dp[i][j][k],dp[i-p.a][j-p.b][k-p.c]+p.v);
        }
    }
    ans += dp[cX][cY][cZ];
    cout << ans << endl;
    return 0;
}

