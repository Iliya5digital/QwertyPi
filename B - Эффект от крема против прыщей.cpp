#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 11;
const int MOD = 998244353;

int a[N];

int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

bool u[N];
int t1, t2;
void add(int d){
    if(!u[d])
        u[d] = true, t1++, t2++;
}

void solve(){
    int n; cin >> n;
    fill(u + 1, u + n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int, int>> b;
    for(int i = 1; i <= n; i++) b.push_back({a[i], i});
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int v = b[i].first, idx = b[i].second;
        int cnt = 0;
        t1 = 0;
        for(int d = 1; d * d <= idx; d++){
            if(d * d == idx) add(d);
            else if(idx % d == 0) add(d), add(idx / d);
        }
        ans += pm(2, n - t2) * (pm(2, t1) - 1) % MOD * v % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}
