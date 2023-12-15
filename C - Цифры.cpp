#include <bits/stdc++.h>
 
using namespace std;
 
string s = "31415926535897932384626433832795028841971";
 
int32_t main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int ans = 1;
        for(int j = 0; j < s[i] - '0'; j++){
            int v; cin >> v; ans *= v;
        }
        cout << ans << endl;
    }
}
