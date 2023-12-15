#include <bits/stdc++.h>
#define int long long

// failed IMO, only got Bronze
// At least give me some CF rating

using namespace std;

const int MAXN = 2e5 + 11;

int f(vector<int> v){
    if(v.empty()) return -(1LL << 60);
    sort(v.begin(), v.end());
    if(v.back() <= 0) return v.back();
    int s = 0;
    for(auto i : v) s += max(0LL, i);
    return s;
}

void solve(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x; v.push_back(x);
    }
    vector<int> o, e;
    for(int i = 0; i < n; i++){
        if(i % 2) o.push_back(v[i]);
        else e.push_back(v[i]);
    }

    int ans = max(f(o), f(e));
    cout << ans << endl;
}

int32_t main(){
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}
