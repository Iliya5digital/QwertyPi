#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    set<int> s;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        int v; cin >> v;
        if(!s.count(v)) ans.push_back(i + 1);
        s.insert(v);
    }
    for(int i = 0; i < n; i++){
        if(ans.size() <= n - 1 - i){
            cout << -1 << ' ';
        }else{
            cout << ans[n - 1 - i] << ' ';
        }
    }
    cout << '\n';
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
