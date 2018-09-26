#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define sc(x) scanf("%d", &x)
using namespace std;

const int maxn = 2e3+10;
struct pnt{
    int L, R;
    pnt(int L=0, int R=0):L(L),R(R){}
    bool operator < (const pnt& r){
        if(L != r.L) return L < r.L;
        return R < r.R;
    }
    bool operator == (const pnt& r){
        return L==r.L && R==r.R;
    }
} p[maxn];
vector<pnt> vp;

pii q[maxn];
int n, m, k, dp[maxn][maxn];
int main(){
    int T; sc(T);
    for(int kase = 1; kase <= T; kase++){
        sc(n); sc(m); sc(k);
        vp.clear();
        for(int i = 0; i < m; i++){
            sc(p[i].L); sc(p[i].R);
        }
        sort(p,p+m);
        m = unique(p,p+m)-p;
        for(int i = 0; i < m; i++){
            int flg = 1;
            for(int j = 0; j < m; j++) if(i != j){
                if(p[i].L >= p[j].L && p[i].R <= p[j].R) flg = 0;
            }
            if(flg) vp.pb(p[i]);
        }
        sort(vp.begin(),vp.end());
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= k; j++){
            int head = 0, tail = 0, pos = 1;
            q[tail++] = mk(0,0);
            for(int i = 0; i < (int)vp.size(); i++){
                int L = vp[i].L, R = vp[i].R;
                while(pos <= R){
                    int x = dp[pos][j-1]-pos, y = pos; pos++;
                    pii now = mk(x,y);
                    while(head < tail && q[tail-1] <= now) tail--;
                    q[tail++] = now;
                }
                while(q[head].se < L-1) head++;
                //printf("j:%d, L:%d, R:%d, q[head]:(%d,%d)\n",j,L,R,q[head].fi,q[head].se);
                dp[R][j] = max(dp[R][j], q[head].fi + R);
            }
            //printf("dp[%d]:",j);
            for(int i = 1; i <= n; i++){
                //printf("%d ", dp[i][j]);
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }//puts("");
        }
        int mx = 0;
        for(int i = 1; i <= n; i++) mx = max(mx, dp[i][k]);
        printf("Case #%d: %d\n", kase, mx);
    }
    return 0;
}
