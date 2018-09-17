#include<iostream>
#include<cstdio>
#include<cstring>
#define sc(x) scanf("%d", &x)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

const int maxn = 1e5+10;
///树链剖分模板
/************************************************/
int val_e[maxn], ///点权与边权
    to[maxn*2], nxt[maxn*2],head[maxn*2], tot;
uLL val_p[maxn];
void tree_init(){
    tot = 0;
    memset(head, 0, sizeof(head));
}
void add_edg(int u, int v, int w = 0){
    tot++; val_e[tot] = w; to[tot] = v;
    nxt[tot] = head[u]; head[u] = tot;
}
void read_edg(int op = 1){///op=1 --> 双向边; op=0 --> 单向边
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edg(u, v, w);
    if(op) add_edg(v, u, w);
}
int tid[maxn],   ///dfs序/tid[i]-->节点i在线段树中的位置
    rk[maxn],    ///rk[i]-->dfs序第i个在树中的节点编号
    top[maxn],   ///所在链顶点
    sz[maxn],    ///子树size
    son[maxn],   ///重儿子
    dep[maxn],   ///深度
    fa[maxn],    ///父节点
    idx;         ///dfs序计数器
void dfs1(int u, int f){
    ///更新dep[u], fa[u], sz[u], son[u]
    //printf("dfs1(%d,%d)\n",u,f);
    dep[u] = dep[f]+1;
    fa[u] = f;
    sz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(son[u] < 0 || sz[v] > sz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int tp){
    ///更新top[u], tid[u], rk[u]
    top[u] = tp;
    tid[u] = idx;
    rk[idx++] = u;
    //printf("%d: top:%d, tid:%d\n",u,top[u],tid[u]);
    //printf("%d ", u);
    if(son[u] >= 0) dfs2(son[u], tp);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
void chain_div(int _n, int rt = 1){///rt取决于题目是否为有根树
    memset(son, -1, sizeof(int)*(_n+5));
    dep[rt] = idx = 0;
    dfs1(rt, rt);
    dfs2(rt, rt);
}
/*************************************************/
///线段树和调用部分仅作参考，赛场上自行发挥
#define lson (((rt)<<1)|1)
#define rson (((rt)<<1)+2)
#define mid (((l)+(r))>>1)

int n;
uLL sum[maxn*4], tag1[maxn*4], tag2[maxn*4];
void build(int rt=0, int l=0, int r=n){
    sum[rt]=tag2[rt]=0; tag1[rt]=1;
    if(l==r-1) return;
    build(lson,l,mid); build(rson,mid,r);
}

/*void spread(LL o){
	LL mul=tree[o].mul,add=tree[o].add;
	tree[o<<1].val=tree[o<<1].val*mul+add*(tree[o<<1].r-tree[o<<1].l+1);
	tree[o<<1|1].val=tree[o<<1|1].val*mul+add*(tree[o<<1|1].r-tree[o<<1|1].l+1);
	tree[o<<1].mul*=mul,tree[o<<1|1].mul*=mul;
	tree[o<<1].add=(tree[o<<1].add*mul+add)%p;
	tree[o<<1|1].add=(tree[o<<1|1].add*mul+add)%p;
	tree[o].mul=1,tree[o].add=0;
	init(o<<1),init(o<<1|1);
}*/
inline void push_down(int rt, int l, int r){
    uLL mul = tag1[rt], add = tag2[rt];
    sum[lson] = sum[lson]*mul+add*(mid-l); 
    sum[rson] = sum[rson]*mul+add*(r-mid);
    tag1[lson] *= mul; tag1[rson] *= mul;
    tag2[lson] = tag2[lson]*mul+add; tag2[rson] = tag2[rson]*mul+add;
    tag1[rt] = 1; tag2[rt] = 0;
}
inline void push_up(int rt){
    sum[rt] = sum[lson]+sum[rson];
}
void mul(int x, int y, int z, int rt=0, int l=0, int r=n){
    //printf("mul(%d,%d,%d,%d,[%d-%d)):%llu\n",x,y,z,rt,l,r,sum[rt]);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
        tag1[rt] *= z; tag2[rt] *= z; sum[rt] *= z;
        //printf("[%d,%d):(%llu,%llu,%llu)\n",l,r,tag1[rt],tag2[rt],sum[rt]);
        return;
    }
    push_down(rt,l,r);
    mul(x,y,z,lson,l,mid); mul(x,y,z,rson,mid,r);
    push_up(rt);
}
void add(int x, int y, int z, int rt=0, int l=0, int r=n){
    //printf("add(%d,%d,%d,%d,[%d-%d)):%llu\n",x,y,z,rt,l,r,sum[rt]);
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
        tag2[rt] += z;
        sum[rt] += ((uLL)(z))*(r-l);
        return;
    }
    push_down(rt,l,r);
    add(x,y,z,lson,l,mid); add(x,y,z,rson,mid,r);
    push_up(rt);
}
uLL query(int x, int y, int rt=0, int l=0, int r=n){
    //printf("query(%d,%d,%d,[%d-%d)):%llu\n",x,y,rt,l,r,sum[rt]);
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return sum[rt];
    push_down(rt,l,r);
    uLL a = query(x,y,lson,l,mid), b = query(x,y,rson,mid,r);
    push_up(rt);
    return a+b;
}
/*pii solve(int u, int v){
    pii ans = mk(-INF, 0);
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        ans = add(ans, query(tid[top[u]], tid[u]));
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ans = add(ans, query(tid[u], tid[v]));
    return ans;
}*/
uLL solve(int u, int v){
    uLL ret = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        ret += query(tid[top[u]], tid[u]+1);
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ret += query(tid[u], tid[v]+1);
    return ret;
}
void upd(int u, int v, int op, int x=0){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        if(op == 1) mul(tid[top[u]], tid[u]+1, x);
        else if(op == 2) add(tid[top[u]], tid[u]+1, x);
        else{
            //printf("sum[11]:%llu\n",sum[11]);
            mul(tid[top[u]], tid[u]+1, -1);
            //printf("sum[11]:%llu\n",sum[11]);
            add(tid[top[u]], tid[u]+1, -1);
            //printf("sum[11]:%llu\n",sum[11]);
        }
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u,v);
    if(op == 1) mul(tid[u], tid[v]+1, x);
    else if(op == 2) add(tid[u], tid[v]+1, x);
    else{
        mul(tid[u], tid[v]+1, -1); //printf("sum[11]:%llu\n",sum[11]);
        add(tid[u], tid[v]+1, -1); //printf("sum[11]:%llu\n",sum[11]);
    }
}
int main(){
    //uLL x = 2;
    //cout << x*(-1) - 1 << endl;
    while(sc(n) != EOF){
        tree_init();
        for(int u = 2; u <= n; u++){
            int v; sc(v);
            add_edg(u,v);
            add_edg(v,u);
        }
        for(int i = 1; i <= n; i++) val_p[i] = 0;
        chain_div(n);
        //puts("");
        //for(int i = 1; i <= n; i++)
            //val[tid[i]] = val_p[i];
        build();
        int q; sc(q);
        while(q--){
            int op, u, v, x;
            sc(op); sc(u); sc(v);
            if(op == 4){
                printf("%llu\n",solve(u,v));
                continue;
            }else if(op == 3){
                upd(u,v,op);       
                continue;
            }
            sc(x);
            upd(u,v,op,x);
        }
    }
    return 0;
}

