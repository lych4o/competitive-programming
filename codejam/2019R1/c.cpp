#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 5e4+10, sigma = 26;
char s[maxn];
struct Trie{
    int nxt[maxn][sigma], num[maxn], idx, ans;
    int newNode(){
        int x = ++idx;
        memset(nxt[x], -1, sizeof(nxt[x]));
		num[x] = 0;
        return x;
    }
    void init(){
        idx = 0;
        memset(nxt[0], -1, sizeof(nxt[0]));
    }
    void insert(){
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = s[i]-'A';
            if(nxt[rt][u] == -1) nxt[rt][u] = newNode();
            rt = nxt[rt][u];
        }
        num[rt]++;
    }
	int get_ans(){
		this->ans = 0;
		dfs(0);
		return this->ans;
	}
	int dfs(int u){
		int tot = num[u];
		for(int i=0;i<26;i++) if(nxt[u][i]>=0){
			tot += dfs(nxt[u][i]);	
		}
		if(u>0 && tot >= 2) tot -= 2, ans += 2;
		return tot;
	}
}trie;
int n;
int main(){
	int T; cin >> T;
	for(int kase=1;kase<=T;kase++){
		cin >> n;
		trie.init();
		for(int i=0;i<n;i++){
			scanf("%s",s);
			reverse(s, s+strlen(s));
			trie.insert();
		}
		printf("Case #%d: %d\n", kase, trie.get_ans());
	}
	return 0;
}
