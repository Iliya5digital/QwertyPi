#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,t; cin >> n >> t; t--;
    vector<ll> a(n + 7);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    n = min(n, t);

    vector<ll> ans(n + 7, 0);
    for (int i = 1; i <= n; i++) {
        if (t >= a[i]) {
            ans[i]++;
            ans[min(n, i + t - a[i]) + 1]--;
        }
    }

    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];

    ll maxv = 0;
    for (int i = 1; i <= n; i++)
        maxv = max(maxv, ans[i]);

    cout << maxv << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
