#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, pair<int, int>> m1, m2;

vector<pair<int, int>> red(int x){
    vector<pair<int, int>> res; set<pair<int, int>> s; set<int> ex; s.insert({0, x});
    while(s.size()){
        auto [c, x] = *s.begin(); s.erase(s.begin());
        res.push_back({c, x});
        if(x % 2 == 0){
            int y = x / 2;
            if(!ex.count(y)){
                ex.insert(y);
                s.insert({c + 1, y});
            }
        }
        if(x % 3 == 0){
            int y = x / 3 * 2;
            if(ex.count(y)) continue;
            ex.insert(y);
            s.insert({c + 1, y});
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve(){
    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;

    vector<pair<int, int>> ra1 = red(a1), ra2 = red(a2), rb1 = red(b1), rb2 = red(b2);

    map<int, pair<int, pair<int, int>>> mp;
    for(auto [c1, x1] : ra1){
        for(auto [c2, x2] : rb1){
            int c = c1 + c2;
            int a = x1 * x2;
            if(!mp.count(a) || mp[a].first > c){ mp[a] = {c, {x1, x2}}; }
        }
    }

    int ans = 1 << 30, _a1, _b1, _a2, _b2;
    for(auto [c1, x1] : ra2){
        for(auto [c2, x2] : rb2){
            int c = c1 + c2;
            int a = x1 * x2;
            if(!mp.count(a)) continue;
            if(mp[a].first + c < ans){
                ans = mp[a].first + c;
                _a1 = mp[a].second.first;
                _b1 = mp[a].second.second;
                _a2 = x1;
                _b2 = x2;
            }
        }
    }

    if(ans == (1 << 30)){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;
    cout << _a1 << ' ' << _b1 << endl;
    cout << _a2 << ' ' << _b2 << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
