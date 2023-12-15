#include <bits/stdc++.h>

#define int long long
using namespace std;

bool u[200001];
void solve(){
    int n, k, x; cin >> n >> k >> x;
    int tot = 0; for(int i = 1; i <= n; i++) tot ^= i;
    if(tot != (k % 2) * x){
        cout << "NO" << endl;
        return;
    }

    fill(u, u + n + 1, false);
    vector<vector<int>> a;
    if(x <= n) a.push_back({x}), u[x] = true;
    for(int i = 1; i <= n; i++){
        int j = i ^ x; if(i < j && j <= n) a.push_back({i, j}), u[i] = u[j] = true;
    }
    if(a.size() % 2 == k % 2){
        for(int i = 1; i <= n; i++) {
            if(!u[i]) {
                if(a.empty()) a.push_back({});
                a.back().push_back(i);
            }
        }
    }else{
        a.push_back({});
        for(int i = 1; i <= n; i++){
            if(!u[i]){
                a.back().push_back(i);
            }
        }
    }

    if(a.size() < k){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
        vector<int> la;
        while(a.size() >= k){
            for(auto i : a.back()) la.push_back(i);
            a.pop_back();
        }
        for(auto v : a){
            cout << v.size() << ' '; for(auto i : v) cout << i << ' '; cout << '\n';
        }
        cout << la.size() << ' '; for(auto i : la) cout << i << ' '; cout << '\n';
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
