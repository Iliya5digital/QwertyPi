#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, n; cin >> x >> y >> n;
    int d = n * (n - 1) / 2;
    if(y - x < d){
        cout << -1 << endl;
    }else{
        cout << x << ' ';
        for(int i = 1; i < n; i++){
            cout << y - ((n - i) - 1) * (n - i) / 2 << ' ';
        }
        cout << endl;
    }
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
