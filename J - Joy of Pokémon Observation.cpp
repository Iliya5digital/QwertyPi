#include <bits/stdc++.h>

#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define forn(i, n) for(int i = 0; i < (n); i++)

typedef long double LD;
typedef long long ll;

const int INF = 1LL << 60;
const LD eps = 1e-9;

using namespace std;

const int MX = 17 * 17 * 17 * 3;
int dp[MX + 1];

int C(int n, int r){
    int res = 1;
    for(int i = 1; i <= r; i++){
        res *= n + 1 - i; res /= i;
    }
    return res;
}
void solve(){
    int t; cin >> t;
    int s; cin >> s;
    vector<int> a;
    for(int i = 0; i < s; i++){
        int v; cin >> v; a.push_back(v);
    }
    fill(dp, dp + MX, 0);
    dp[0] = 1;
    int L = 1; for(auto v : a) L *= v;
    for(int i = 0; i < s; i++){
        for(int p = 0; p < a[i]; p++){
            int ST = (MX - a[i]) / a[i] * a[i] + p;
            int ps = 0; for(int j = 1; j < L / a[i]; j++) ps += dp[ST - a[i] * j];
            for(int j = ST; j >= 0; j -= a[i]){
                dp[j] += ps;
                if(j - a[i] >= 0)
                    ps -= dp[j - a[i]];
                if(j - L >= 0)
                    ps += dp[j - L];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < MX; i++){
        if(t % L != i % L || i > t) continue;
        int D = (t - i) / L;
        ans += dp[i] * C(D + s - 1, s - 1);
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
