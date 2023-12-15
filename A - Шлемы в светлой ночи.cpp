#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 11;
int a[N], b[N];

struct ppl{
    int a, b;
};

void solve(){
    int n, p; cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<ppl> P; for(int i = 0; i < n; i++) P.push_back({a[i], b[i]});
    P.push_back({n - 1, p});
    sort(P.begin(), P.end(), [](auto a, auto b){ return a.b < b.b; });

    int ans = p; int cnt = n - 1;
    for(auto [a, b] : P){
        for(int j = 0; j < a && cnt > 0; j++){
            ans += b; cnt--;
        }
    }
    cout << ans << '\n';
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
