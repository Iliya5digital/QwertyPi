#include <bits/stdc++.h>

#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define forn(i, n) for(int i = 0; i < (n); i++)

typedef long double LD;
typedef long long ll;

const int INF = 1LL << 60;
const int MOD = 998244353;
const LD eps = 1e-9;

using namespace std;

const int N = 2e5 + 11;
int dp[N][3][3][3];
int a[N];
const int EVEN = 0;
const int ODD = 1;
const int NONE = 2;

int chadd(int& x, int y){ x += y; x %= MOD; return x; }

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i] %= 2;
    }
    dp[0][NONE][NONE][NONE] = 1;
    for(int i = 0; i < n; i++){
        // not choosing
        forn(x, 3) forn(y, 3) forn(z, 3)
            dp[i + 1][x][y][z] = dp[i][x][y][z];
        
        // choosing
        forn(x, 3) forn(y, 3) forn(z, 3) if(y == NONE || z == NONE || (y + z + a[i]) % 2 == 0)
            chadd(dp[i + 1][y][z][a[i]], dp[i][x][y][z]);
    }
    int ans = 0;
    forn(x, 2) forn(y, 2) forn(z, 2)
        ans += dp[n][x][y][z];
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
