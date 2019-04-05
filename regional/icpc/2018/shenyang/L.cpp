#include<bits/stdc++.h>
#define sp putchar(' ')
#define ln puts("")
#define mk make_pair
#define pb push_back
#define SZ(x) ((int)x.size())
#define pdd pair<db,db>
using namespace std;
typedef long double db;
const db eps = 1e-10;
inline int dcmp(db x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct P{
    db x, y;
    P(db x=0,db y=0):x(x),y(y){}
    void print(){printf("(%.3Lf,%.3Lf)",x,y);}
    bool operator == (const P& rhs) const{
        return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0;
    }
    bool operator < (const P& rhs) const{
        return atan2(y,x)<atan2(rhs.y,rhs.x);
    }
};
typedef P V;
V operator - (V a, V b){return V(a.x-b.x,a.y-b.y);}
struct C{
    P c; db r;
    C(P c=P(), db r=0):c(c),r(r){}
    P point(db a){
        return P(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
db Cross(V a, V b){return a.x*b.y-a.y*b.x;}
db Dot(V a,V b){return a.x*b.x+a.y*b.y;}
db Length(V v){return sqrt(Dot(v,v));}
db angle(V v){return atan2(v.y,v.x);}
int CCInte(C C1, C C2, vector<P>& sol){
    db d=Length(C1.c-C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0) return -1;
        return 0;
    }
    if(dcmp(C1.r+C2.r-d)<0) return 0;
    if(dcmp(fabs(C1.r-C2.r)-d)>0) return 0;
    db a = angle(C2.c-C1.c);
    db da = acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    P p1=C1.point(a-da), p2=C1.point(a+da);
    //p1.print();  p2.print(); ln;
    sol.pb(p1);
    if(p1==p2) return 1;
    sol.pb(p2);
    return 2;
}

int n;
C c;
C cc[200];
vector<P> vp;
int main(){
    int T; cin >> T;
    for(int kase=1;kase<=T;kase++){
        C tmp;
        c.c=P(0,0);
        scanf("%d%Lf",&n,&c.r);
        vp.clear();
        for(int i=0;i<n;i++){
            scanf("%Lf%Lf%Lf",&cc[i].c.x,&cc[i].c.y,&cc[i].r);
            //printf("%d\n",CCInte(c,tmp,vp));
            CCInte(c,cc[i],vp);
        }
        db mx=0;
        for(int i=0;i<SZ(vp);i++){
            int flg=0;
            for(int j=0;j<n;j++){
                P q = P(-vp[i].x,-vp[i].y);
                if(dcmp(Length(q-cc[j].c)-cc[j].r)<0) flg=1;
            }
            if(!flg) mx = 2*c.r;
        }
        /*for(int i=0;i<SZ(vp);i++){
            vp[i].print(); ln;
        }*/
        for(int i=0;i<SZ(vp);i++) for(int j=i+1;j<SZ(vp);j++){
            mx=max(mx,Length(vp[i]-vp[j]));
        }
        printf("Case #%d: %.15Lf\n",kase,mx);
    }
    return 0;
}
