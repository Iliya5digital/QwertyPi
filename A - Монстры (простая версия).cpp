#include <bits/stdc++.h>

using namespace std;

int a[200001];
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i]; sort(a, a + n + 1);
    long long ans = 0;
    for(int i = 1; i <= n; i++){ if(a[i] > a[i - 1] + 1) ans += a[i] - a[i - 1] - 1, a[i] = a[i - 1] + 1; }
    bool all_zero = true; for(int i = 1; i <= n; i++) if(a[i] != 0) all_zero = false;
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
