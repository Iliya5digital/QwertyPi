#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int N = 2e5 + 11;

int c[N], a[N];
void solve(){
    int n; cin >> n; for(int i = 0; i < n; i++) cin >> c[i];
    int k; cin >> k;
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++){
        while(b.size() && b.back().se >= c[i]) b.pop_back();
        b.push_back({i, c[i]});
    }
    fill(a, a + n, 0);
    int prv = 0, prv_i = -1, cur = 1 << 30;
    for(auto [i, v] : b){
        int g = min(cur, k / (v - prv));
        a[i] += g; if(prv_i != -1) a[prv_i] -= g;
        k -= (v - prv) * g;
        cur = min(cur, g);
        prv = v; prv_i = i;
    }
    for(int i = n - 2; i >= 0; i--) a[i] += a[i + 1];
    for(int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
