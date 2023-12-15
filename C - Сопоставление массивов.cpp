#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 11;
int a[N], b[N], c[N];

void solve(){
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end());
    sort(b, b + n);

    for(int i = 0; i < x; i++) {
        c[v[n - x + i].second] = b[i];
    }
    for(int i = 0; i < n - x; i++){
        c[v[i].second] = b[x + i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > c[i]) cnt++;
    }
    if (cnt != x){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for(int i = 0; i < n; i++) cout << c[i] << ' ';
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
