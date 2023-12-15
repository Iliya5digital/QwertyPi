#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n, k, x; cin >> n >> k >> x;
    if(k > x + 1){
        cout << -1 << '\n';
    }else if(k == 0){
        cout << -1 << '\n';
    }else if(k > n){
        cout << -1 << '\n';
    }else if(x == k){
        int ans = 0;
        for(int i = 0; i < k; i++) ans += i;
        for(int i = k; i < n; i++) ans += k - 1;
        cout << ans << '\n';
    }else{
        int ans = 0;
        for(int i = 0; i < k; i++) ans += i;
        for(int i = k; i < n; i++) ans += x;
        cout << ans << '\n';
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
