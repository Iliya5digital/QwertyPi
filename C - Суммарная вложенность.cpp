#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n,k; cin >> n >> k;
    const ll THRES = 1e11;
    if (k >= THRES) {
        cout << "Impossible\n";
        return;
    }

    ll len = 1;
    while (len * (len + 1) < 2 * k) len++;

    const ll totalK = len * (len - 1) / 2;
    const ll extraDep = k - totalK;
    const ll need = len + (k > totalK);
    if (need > n) {
        cout << "Impossible\n";
        return;
    }

    string ans(len, '(');
    ll curDepth = len;
    while (curDepth > extraDep) {
        ans += ')';
        curDepth--;
    }
    if (curDepth != 0) {
        curDepth++;
        ans += '(';
    }
    while (curDepth > 0) {
        ans += ')';
        curDepth--;
    }

    const ll rem = n - need;
    for (int i = 0; i < rem; i++)
        ans += "()";

    cout << ans << '\n';
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
