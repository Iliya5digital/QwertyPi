#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

const int N = 5e3 + 11;
int a[N];
int dp[N][N], s[N][N];
int pw2[N];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 1;
    pw2[0] = 1; for(int i = 1; i <= n; i++) pw2[i] = pw2[i - 1] * 2 % MOD;
    for(int i = 1; i < n; i++){
        int s = 0;
        for(int j = 0; j <= i - 1; j++){
            if(a[i - 1] < a[i]){
                s += dp[i - 1][j]; s %= MOD;
                dp[i][j] = s * pw2[i - j - 1] % MOD;
            }else{
                dp[i][j] = s * pw2[i - j - 1] % MOD;
                s += dp[i - 1][j]; s %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += dp[n - 1][i]; ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
