#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
const double eps=1e-9;
 
struct point
{
    int x,y;
}pp[100005];
typedef point Vector;
Vector vc[100005];
int sum1=0,sum2=0,sum3=0,sum4=0;
double dot(Vector a,Vector b)
{
    return 1.0*a.x*b.y-1.0*a.y*b.x;
}
 
 
int quad(Vector a)// 判断象限的函数，每个象限包括半个坐标轴
{
    if( a.x>=0 && a.y>0 ) return 1;
    if( a.x<0 && a.y>=0 ) return 2;
    if( a.x<=0 && a.y<0 ) return 3;
    if( a.x>0 && a.y<=0 ) return 4;
}
bool operator < (const Vector &a,const Vector &b)
{
    Vector p1 = a,p2 = b;
    int l1,l2;
    l1 = quad(p1); l2 = quad(p2);
    if( l1 == l2 )
    {
        if(dot(a,b)>0)
            return true;
        else
            return false;
    }
    return l1 < l2;
}
 
int main()
{
    int n;
    cin>>n;
    int sum5=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&pp[i].x,&pp[i].y);
        vc[i].x=pp[i].x-pp[0].x,vc[i].y=pp[i].y-pp[0].y;
        if(vc[i].x==0&&vc[i].y==0){
            vc[i].x=vc[i].y=1;
            sum5++;
        }
        if(i==0)
            continue;
        if(vc[i].x>=0)
            sum1++;
        if(vc[i].x>0)
            sum2++;
        if(vc[i].y>=0)
            sum3++;
        if(vc[i].y>0)
            sum4++;
    }
    sort(vc+1,vc+n);
    /*for(int i=1;i<n;i++)
        cout<<vc[i].x<<' '<<vc[i].y<<endl;*/
    int ans1=0,ans2=10000000;
    for(int i=1;i<n;i++)
    {
        if((vc[i].x<=0&&vc[i].y>=0))
        {
            //cout<<i<<endl;
            Vector a;
            a.x=-1*vc[i].x,a.y=-1*vc[i].y;
            int c=lower_bound(vc+1,vc+n,a)-vc;
            int d=upper_bound(vc+1,vc+n,a)-vc;
            int now=i;
            if(c>=i)now+=n-1;
            else if(d>=i)now+=n-1;
            //cout<<c<<d<<endl;
            ans1=max((now-c+1)+1,ans1);
            ans2=min((now-d+1-sum5)+1,ans2);
            //cout<<c<<' '<<d<<' '<<i<<' '<<ans1<<' '<<ans2<<endl;
        }
        else
            continue;
    }
    ans1=max(ans1,sum1+1);
    ans1=max(ans1,sum3+1);
    ans2=min(ans2,sum2+1);
    ans2=min(ans2,sum4+1);
    cout<<ans2<<' '<<ans1<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
