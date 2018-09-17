#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define piL pair<int, long long>
#define fi first
#define se second
#define mk make_pair
#define fout fflush(stdout)
#define sc(x) scanf("%d", &x)
#define pb push_back

using namespace std;
typedef long long LL;

//fread版本
namespace IO {
    const int MT = 27 * 1024 * 1024;  /// 10MB 请注意输入数据的大小！！！
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;
    /// 要记得把这一行添加到main函数第一行！！！
    void begin() {
        IO_PTR = 0;
        IO_SZ = fread (IO_BUF, 1, MT, stdin);
    }
    template<typename T>
    inline bool scan_d (T & t) {
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' && (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
            IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        bool sgn = false;
        if (IO_BUF[IO_PTR] == '-') sgn = true, IO_PTR ++;
        for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9'; IO_PTR ++)
            t = t * 10 + IO_BUF[IO_PTR] - '0';
        if (sgn) t = -t;
        return true;
    }
    inline bool scan_s (char s[]) {
        while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n') ) IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        int len = 0;
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
            s[len ++] = IO_BUF[IO_PTR], IO_PTR ++;
        s[len] = '\0';
        return true;
    }
    template<typename T>
    void print(T x) {
        static char s[33], *s1; s1 = s;
        if (!x) *s1++ = '0';
        if (x < 0) putchar('-'), x = -x;
        while(x) *s1++ = (x % 10 + '0'), x /= 10;
        while(s1-- != s) putchar(*s1);
    }
    template<typename T>
    void println(T x) {
        print(x); putchar('\n');
    }
};

const int maxn = 1e5+10;
int ls[maxn*30],rs[maxn*30],root[maxn],n,
    a[maxn],tot,sum[maxn*30];

#define mid (((l)+(r))/2)
void build(int& rt, int l=1, int r=maxn){
    rt = tot++; sum[rt] = 0;
    if(l==r-1) return ;
    build(ls[rt],l,mid);
    build(rs[rt],mid,r);
}
void update(int last, int& rt, int v, int l=1, int r=maxn){
    rt = tot++;
    sum[rt] = sum[last]+1;
    if(l==r-1) return;
    if(v >= mid){
        ls[rt] = ls[last];
        update(rs[last], rs[rt], v, mid, r);
    }else{
        rs[rt] = rs[last];
        update(ls[last], ls[rt], v, l, mid);
    }
}
int query(int x, int y, int rt, int l=1, int r=maxn){
    //printf("query(%d,%d,%d,[%d,%d)):%d\n",x,y,rt,l,r,sum[rt]);
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return sum[rt];
    int a = query(x,y,ls[rt],l,mid), b = query(x,y,rs[rt],mid,r);
    return a+b;
}

int bit[maxn];
inline int lowbit(int x){return x&-x;}
inline void add(int x, int v){
    for(int i = x; i < maxn; i += lowbit(i))
        bit[i] += v;
}
inline int bsum(int x){
    int ret = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        ret += bit[i];
    return ret;
}
inline void del(int l, int r){
    for(int i = l; i <= r; i++) add(a[i],-1);
}
set<piL> pos;
multiset<LL> st;
void init(){
    tot=0;
    st.clear();
    pos.clear();
}

inline LL get(int l, int r){
    LL ret = 0;
    for(int i = l; i <= r; i++){
        add(a[i],1);
        ret += bsum(maxn-1)-bsum(a[i]);
    }
    del(l,r);
    //printf("get(%d,%d):%lld\n",l,r,ret);
    return ret;
}
void DEBUG(){
    int p, l, r;
    while(cin >> p >> l >> r) cout << query(l,r,root[p]) << endl;
}
int main(){
    IO::begin();
    int T; 
    IO::scan_d(T);
    //sc(T);
    while(T--){
        init();
        IO::scan_d(n); 
        //sc(n);
        build(root[0]);
        LL tmp = 0;
        for(int i = 1; i <= n; i++){
            IO::scan_d(a[i]);
            //sc(a[i]);
            update(root[i-1],root[i],a[i]);
            //printf("tot:%d\n",tot);
            add(a[i], 1);
            tmp += bsum(maxn-1)-bsum(a[i]);
            //printf("a[%d]:%d, tmp:%lld\n",i,a[i],tmp); fout;
        } del(1,n);
        //DEBUG();
        st.insert(tmp);
        LL ans = 0;
        pos.insert(mk(0,0LL)); pos.insert(mk(n,tmp));
        for(int i = 1; i <= n; i++){
            printf("%lld%c", ans=*st.rbegin(), " \n"[i==n]); fout;
            //LL shit; scanf("%lld", &shit); shit ^= ans; int p = shit;
            //LL shit; IO::scan_d(shit); shit ^= ans; int p = shit;
            int p; 
            IO::scan_d(p);
            //sc(p);
            set<piL>::iterator it = pos.lower_bound(mk(p,0LL));
            LL all = it->se;
            int R = it->fi, L = ((--it)->fi) + 1;
            LL lval, rval; 
            if(p-L>R-p){
                lval = get(L,p-1); rval = all - lval;
                for(int i = L; i <= p; i++){
                    rval -= query(1,a[i],root[R]);
                    rval += query(1,a[i],root[p-1]);
                    //printf("query(%d,%d,%d):%d,query(%d,%d,%d):%d\n",
                      //  1,a[i],root[R],query(1,a[i],root[R]),
                       // 1,a[i],root[p],query(1,a[i],root[p]));
                }
            }else{
                rval = get(p+1,R); lval = all - rval;
                for(int i = p; i <= R; i++){
                    lval -= query(a[i]+1,maxn,root[p]);
                    lval += query(a[i]+1,maxn,root[L-1]);
                }
            }
            //printf("p:%d, L:%d, R:%d, lval:%lld, rval:%lld\n",p,L,R,lval,rval);
            pos.erase(++it);
            pos.insert(mk(p,0LL));
            if(p > L) pos.insert(mk(p-1,lval));
            if(R > p) pos.insert(mk(R,rval));
            st.erase(st.lower_bound(all));
            st.insert(lval); st.insert(rval);
        }
    }
    return 0;
}
