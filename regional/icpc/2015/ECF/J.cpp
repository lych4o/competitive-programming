#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
using namespace std;
typedef double db;
const int maxn = 1e5+10;
const db eps = 1e-8;
int sgn(db x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
int n;
db a[maxn], p[maxn];

int check(db mid){
    db L = mid, R = mid;
    for(int i=0;i<n;i++){
        if(sgn(p[i] = mid*mid-a[i])<0) return 0;
        if(L<R) swap(L,R);
        L = min(L, sqrt(p[i]));
        if(sgn(L-1)>=0) L -= 1;
        else{
            if(sgn(L+R-1)<0) return 0;
            if(sqr(1-L)+a[i]>mid*mid) return 0;
            if(i!=n-1) return 0;
        }
    }
    return 1;
}
int main(){
    int T; scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            db x,y; scanf("%lf%lf",&x,&y);
            if(x<y) swap(x,y);
            a[i]=sqr(x/2)+sqr(y);
        }
        sort(a,a+n);
        db L = 0, R = 1e6;
        for(int t=0;t<200;t++){
            db mid = (L+R)/2;
            if(check(mid)) R = mid;
            else L = mid;
        }
        printf("Case #%d: %.8f\n", kase, R);
    }
    return 0;
}
