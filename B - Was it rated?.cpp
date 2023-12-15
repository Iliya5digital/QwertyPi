#include <bits/stdc++.h>
 
using namespace std;
 
bool b[25] = {1, 1, 1, 1, 1,
              1, 1, 1, 1, 1,
              1, 1, 1, 1, 0, 
              1, 1, 1, 1, 0, 
              0, 1, 1, 1, 1};
int32_t main(){
    int n; cin >> n;
    cout << (b[n - 1] ? "YES" : "NO") << endl;
}
