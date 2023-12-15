#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    if(m == 1){
        cout << 0 << '\n';
    }else{
        cout << min(m, n + 1) << '\n';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << (max(i, n - m + 1) + j) % m << ' ';
        }
        cout << '\n';
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
