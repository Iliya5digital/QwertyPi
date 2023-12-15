#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

void solve(){
    int n; cin >> n; string s; cin >> s;
    int L = 0, R = n - 1;
    while(s[L] == 'B' && L <= R) L++;
    while(s[R] == 'A' && L <= R) R--;
    cout << max(0LL, R - L) << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
