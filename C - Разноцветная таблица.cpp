#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int N = 1e5 + 11;
int ans[N], a[N];

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++) vp.push_back({a[i], i});
    sort(vp.begin(), vp.end(), [](auto a, auto b){ return a.first > b.first; });
    int L = n + 1, R = -1;
    fill(ans + 1, ans + k + 1, 0);
    for(auto [v, i] : vp){
        L = min(L, i), R = max(R, i);
        ans[v] = max(ans[v], R - L + 1);
    }
    for(int i = 1; i <= k; i++){
        cout << ans[i] * 2 << ' ';
    }
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
