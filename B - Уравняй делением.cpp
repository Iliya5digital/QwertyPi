#include <bits/stdc++.h>

using namespace std;

int a[101];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool all_1 = true, ex_1 = false; for(int i = 0; i < n; i++) all_1 &= a[i] == 1, ex_1 |= a[i] == 1;
    if(all_1 || n == 1){
        cout << 0 << endl;
        return;
    }else if(ex_1){
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> ans;
    while(true){
        bool upd = false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] > a[j]){
                    ans.push_back({i, j});
                    a[i] = (a[i] + a[j] - 1) / a[j];
                    upd = true;
                }else if(a[j] > a[i]){
                    ans.push_back({j, i});
                    a[j] = (a[j] + a[i] - 1) / a[i];
                    upd = true;
                }
            }
        }
        if(!upd) break;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
