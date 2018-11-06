#include<bits/stdc++.h>
#define sc(x) scanf("%d",&x)
#define sll(x) scanf("%lld", &x)
#define pb push_back
#define sqr(x) ((x)*(x))
#define ln puts("")
#define sp putchar(' ')
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const db eps = 1e-11;
const db PI = acos(-1.0);
const int maxn = 1e3+10;

inline int dcmp(db x){
    if(fabs(x)<eps) return 0;
    return x < 0 ? -1 : 1;
}
struct P{
    db x,y;
    P(db x=0,db y=0):x(x),y(y){}
    void print(){ printf("(%.7f,%.7f)",(double)x,(double)y);}
    P operator + (const P& r) const{return P(x+r.x,y+r.y);}
    P operator - (const P& r) const{return P(x-r.x,y-r.y);}
    P operator * (const db p) const {return P(x*p,y*p);}
    bool operator < (const P& r) const{ return x<r.x || (x==r.x&&y<r.y);}
};
typedef P V;
db abs(V a){return sqrt(a.x*a.x+a.y*a.y);}
db cross(V a, V b){return a.x*b.y-a.y*b.x;}
db Dot(V a, V b){return a.x*b.x+a.y*b.y;}

/*P crosspt(const P& a, const P& b, const P& p, const P& q){
    db a1=cross(b-a,p-a), a2=cross(b-a,q-a);
    return (p*a2-q*a1)*(1.0/(a2-a1));
}*/
P pp[maxn], res[maxn], a, b;
int n;
db k, r;
db mysqrt(double n){ return sqrt(max(0.0,n));}
db sector_area(const P& a, const P& b){
    db theta = atan2(a.y,a.x)-atan2(b.y,b.x);
    while(theta<=0) theta += 2*PI;
    while(theta>2*PI) theta -= 2*PI;
    theta = min(theta, 2*PI - theta);
    return r*r*theta/2;
}
void circle_cross_line(P a, P b, P o, double r, P ret[], int& num){
    db x0=o.x, y0=o.y,
       x1=a.x, y1=a.y,
       x2=b.x, y2=b.y,
       dx = x2-x1, dy = y2-y1,
       A = dx*dx+dy*dy,
       B = 2*dx*(x1-x0)+2*dy*(y1-0),
       C = sqr(x1-x0)+sqr(y1-y0)-sqr(r),
       delta = B*B-4*A*C;
    num = 0;
    if(dcmp(delta)>=0){
        db t1 = (-B-mysqrt(delta))/(2*A);
        db t2 = (-B+mysqrt(delta))/(2*A);
        if(dcmp(t1-1)<=0&&dcmp(t1)>=0){
            ret[num++] = P(x1 + t1*dx, y1 + t1*dy);
        }
        if(dcmp(t2-1)<=0&&dcmp(t2)>=0){
            ret[num++] = P(x1 + t2*dx, y1 + t2*dy);
        }
    }
}
double calc(const P& a, const P& b){
    P p[2];
    int num = 0,
    ina = dcmp(abs(a)-r)<0,
    inb = dcmp(abs(b)-r)<0;
    //printf("ina:%d, inb:%d\n",ina,inb);
    if(ina){
        if(inb){
            return fabs(cross(a,b))/2.0;
        }else{
            circle_cross_line(a,b,P(0,0),r,p,num);
            return sector_area(b,p[0])+fabs(cross(a,p[0]))/2.0;
        }
    }else{
        if(inb){
            circle_cross_line(a,b,P(0,0),r,p,num);
            return sector_area(p[0],a)+fabs(cross(p[0],b))/2.0;
        }else{
            circle_cross_line(a,b,P(0,0),r,p,num);
            if(num==2){
                return sector_area(a,p[0]) + sector_area(p[1],b)
                    + fabs(cross(p[0],p[1]))/2.0;
            }else{
                return sector_area(a,b);
            }
        }
    }
}
db area(){
    res[n]=res[0];
    db ret = 0;
    for(int i=0; i<n; i++){
        int sgn = dcmp(cross(res[i],res[i+1]));
        if(sgn!=0){
            ret += sgn*calc(res[i],res[i+1]);
        }
    }
    return ret;
}
int convex(P* p, int n, P* ch){
    sort(p,p+n);
    int m = 0;
    for(int i=0;i<n;i++){
        while(m>1 && cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i=n-2;i>=0;i--){
        while(m>k && cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0) m--;
        ch[m++] = p[i];
    }
    if(n>1) m--;
    return m;
}

int main(){
    int kase = 1;
    while(scanf("%d%lf",&n,&k)!=EOF){
        for(int i = 0; i < n; i++) scanf("%lf%lf",&pp[i].x,&pp[i].y);
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        /*db xc = (b.x-2*k*k*a.x)/(1-k*k), 
           yc = (b.y-2*k*k*a.y)/(1-k*k);
        r = -b.x*b.x+k*k*a.x*a.x-b.y*b.y+k*k*a.y*a.y;
        r /= (1-k*k);
        r += xc*xc+yc*yc;
        r = sqrt(r);
        P c = P(xc,yc); */
        //cc.print(); printf("%.3f\n",r);
        V v = b-a;
        P p1=a+v*(1/(1+k)),p2=a+v*(1/(1-k)),c=(p1+p2)*0.5;r = abs(p1-c);
        //p1.print(); p2.print(); 
        //c.print(); printf("r:%.7f\n",r);
        for(int i = 0; i < n; i++) pp[i] = pp[i]-c;
        for(int i = 0; i < n; i++) res[i]=pp[i];
        //n = convex(pp, n, res);
        //for(int i = 0; i < n; i++){
         //   res[i].print(); ln;
        //}
        printf("Case %d: %.7f\n", kase++, fabs((double)area()));
    }
    return 0;
}
