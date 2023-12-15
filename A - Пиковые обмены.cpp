#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int a[11];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << (a[0] == 1 ? "Yes" : "No") << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
