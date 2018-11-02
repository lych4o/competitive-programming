#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#define piL pair<int, long long>
#define fi first
#define se second
#define mk make_pair
#define fout fflush(stdout)
#define sc(x) scanf("%d", &x)
#define pb push_back

using namespace std;
typedef long long LL;

const int maxn = 1e5+10;
int ls[maxn*20],rs[maxn*20],root[maxn],n,
    a[maxn],tot,sum[maxn*20];

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
#define mid (((l)+(r))>>1)
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
int query(int x, int y, int rtL, int rtR, int l=1, int r=maxn){
    //printf("query([%d,%d),[%d,%d)):%d\n",x,y,l,r,sum[rtR]-sum[rtL]);fout;
    if(l >= y || r <= x || x >= y) return 0;
    if(l >= x && r <= y) return sum[rtR]-sum[rtL];
    int a = query(x,y,ls[rtL],ls[rtR],l,mid),
      b = query(x,y,rs[rtL],rs[rtR],mid,r);
    return a+b;
}
int qsum(int x, int y, int l, int r){
    if(r-l >= 17){
        int ret = 0;
        for(int i = l; i <= r; i++) ret += (a[i]>=x && a[i]<y);
        return ret;
    }
    return query(x,y,root[l-1],root[r]);
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
set<int> pos;
multiset<LL> st;
LL ans[maxn];

void init(){
    tot=0;
    pos.clear();
    st.clear();
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
    int p1, p2, l, r;
    while(cin >> p1 >> p2 >> l >> r) cout << query(l,r,root[p1],root[p2]) << endl;
}
#define FASTIO
int main(){
#ifdef FASTIO
    IO::begin();
#endif
    int T; 
#ifdef FASTIO
    IO::scan_d(T);
#else
    sc(T);
#endif
    while(T--){
        init();
#ifdef FASTIO
        IO::scan_d(n);
#else
        sc(n); 
#endif
        build(root[0]); LL tmp = 0;
        //int now = clock();
        for(int i = 1; i <= n; i++){
#ifdef FASTIO
            IO::scan_d(a[i]);
#else
            sc(a[i]);
#endif
            update(root[i-1],root[i],a[i]);
            //printf("tot:%d\n",tot);
            add(a[i], 1);
            tmp += bsum(maxn-1)-bsum(a[i]);
            //printf("a[%d]:%d, tmp:%lld\n",i,a[i],tmp); fout;
        } del(1,n);
        //printf("%lu\n",(clock()-now)/1000);
        ans[n] = tmp;
        st.insert(tmp);
        //DEBUG();
        LL res = 0;
        pos.insert(n+1); pos.insert(0);
        for(int i = 1; i <= n; i++){
#ifdef FASTIO
            res = *st.rbegin();
            IO::print(res); printf("%c", " \n"[i==n]); fout;
            LL shit; IO::scan_d(shit); shit ^= res; int p = shit;
#else
            printf("%lld%c", res=*st.rbegin(), " \n"[i==n]);
            LL shit; scanf("%lld", &shit); shit ^= res; int p = shit;
#endif
            //int p; 
            //sc(p);
            //IO::scan_d(p);
            auto it = pos.lower_bound(p);
            int R = *it-1, L = (*(--it))+1;
            LL all = ans[R], lval = 0, rval = 0;
            all -= query(a[p]+1,maxn,root[L-1],root[p]);
            all -= query(1,a[p],root[p],root[R]);
            //printf("p;%d, L:%d, R:%d, all:%lld\n",p,L,R,all); fout;
            int thre = 17;
            if(max(R-p,p-L) <= thre){
                for(int i = L; i < p; i++) for(int j = i+1; j < p; j++){
                    lval += a[i]>a[j];
                }
                for(int i = p+1; i <= R; i++) for(int j = i+1; j <= R; j++){
                    rval += a[i]>a[j];
                }
            }else
#define fuck
            if(p-L<R-p){
#ifdef fuck
                for(int i = L; i < p; i++){
                    add(a[i],1);
                    lval += bsum(maxn-1)-bsum(a[i]);
                    rval -= query(1,a[i],root[p],root[R]);
                }
                rval += all-lval;
                for(int i = L; i < p; i++) add(a[i],-1);
#else
                lval = get(L,p-1); rval = all - lval;
                for(int i = L; i <= p; i++){
                    rval -= query(1,a[i],root[p-1],root[R]);
                }
#endif
            }else{
#ifdef fuck
                for(int i = p+1; i <= R; i++){
                    add(a[i],1);
                    rval += bsum(maxn-1)-bsum(a[i]);
                    lval -= query(a[i]+1,maxn,root[L-1],root[p-1]);
                }
                lval += all-rval;
                for(int i = p+1; i <= R; i++) add(a[i],-1);
#else
                rval = get(p+1,R); lval = all - rval;
                for(int i = p; i <= R; i++){
                    lval -= query(a[i]+1,maxn,root[L-1],root[p]);
                }
#endif
            }
            //printf("p:%d, L:%d, R:%d, lval:%lld, rval:%lld\n",p,L,R,lval,rval);
            st.erase(st.lower_bound(ans[R]));
            pos.insert(p); ans[p] = 0;
            //printf("lval:%lld, rval:%lld\n",lval,rval);fout;
            if(R>p) st.insert(ans[R]=rval);
            if(p>L) st.insert(ans[p-1]=lval);
        }
    }
    return 0;
}

