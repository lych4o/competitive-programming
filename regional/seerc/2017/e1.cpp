#include <bits/stdc++.h>
#define sp putchar(' ')
#define debug puts("???")
#define ln puts("")
using namespace std;

const int N = 10000005;

map<string, int> f;
int n, a[N];
bool ok[N];

void print(int x){
	int cnt=0,rcd[20];
	while(x>0) rcd[cnt++]=x&1, x>>=1;
	for(int i=cnt-1;i>=0;i--) printf("%d",rcd[i]);
}
int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  f["Do"] = 0;
  f["Do#"] = 1;
  f["Re"] = 2;
  f["Re#"] = 3;
  f["Mi"] = 4;
  f["Fa"] = 5;
  f["Fa#"] = 6;
  f["Sol"] = 7;
  f["Sol#"] = 8;
  f["La"] = 9;
  f["La#"] = 10;
  f["Si"] = 11;
  for (int i = 0; i < 12; ++i) {
    int s = 0;
    s |= 1 << (i + 0) % 12;
    s |= 1 << (i + 2) % 12;
    s |= 1 << (i + 4) % 12;
    s |= 1 << (i + 5) % 12;
    s |= 1 << (i + 7) % 12;
    s |= 1 << (i + 9) % 12;
    s |= 1 << (i + 11) % 12;
    ok[s] = true;
  }
  for (int i = 1; i < 1 << 12; i <<= 1) {
    for (int j = 0; j < 1 << 12; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        ok[j + k] |= ok[j + k + i];
      }
    }
  }
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    a[i] = f[s];
  }
  int answer = n;
  for (int i = 0; i < 12; ++i) {
    int s = 0;
    s |= 1 << (i + 0) % 12;
    s |= 1 << (i + 2) % 12;
    s |= 1 << (i + 4) % 12;
    s |= 1 << (i + 5) % 12;
    s |= 1 << (i + 7) % 12;
    s |= 1 << (i + 9) % 12;
    s |= 1 << (i + 11) % 12;
    int l = 1, r = n;
    while (l <= n && (s >> a[l] & 1)) {
      ++l;
    }
    while (r && (s >> a[r] & 1)) {
      --r;
    }
    int result = 1, state = (1 << 12) - 1;
    for (int j = l; j <= r; ++j) {
	  //printf("j:%d, ",j); 
	  //print(state); sp; print(state|1<<a[j]); 
	  sp; print(state|(1<<a[j])); ln;
      if (!ok[state | 1 << a[j]]) {
        state = 1 << a[j];
        ++result;
      } else {
		  //debug;
        state |= 1 << a[j];
      }
    }
	//printf("ms[%d]:%d\n",i,result);
    answer = min(answer, result);
  }
  printf("%d\n", answer);
  return 0;
}
