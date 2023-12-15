#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 11;
int a[N];
void solve(){
    int n, c; cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> b;
    for(int i = 2; i <= n; i++){
        if(a[i] >= i * c) a[1] += a[i];
        else b.push_back({i * c - a[i], a[i]});
    }
    sort(b.begin(), b.end());
    for(auto x : b){
        if(a[1] >= x.first) a[1] += x.second;
        else { cout << "No" << '\n'; return; }
    }
    cout << "Yes" << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
