#include<bits/stdc++.h>

using namespace std;

string s;
int n;
int main(){
    int T; cin >> T;
    while(T--){
        cin >> n >> s;
        if(s.size()==2&&s[0]>=s[1]) printf("NO\n");
        else{
            printf("YES\n2\n");
            cout << s.substr(0,1) << ' ' << s.substr(1,n-1) << endl;
        }
    }
    return 0;
}
