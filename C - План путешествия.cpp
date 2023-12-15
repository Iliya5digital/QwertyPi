#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

int pm(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

int mi(int a){
    return pm(a, MOD - 2);
}

const int L_MAX = 120 + 11;
const int M_MAX = 1e5 + 11;
int v[L_MAX][M_MAX], pv[L_MAX][M_MAX];

int f(int n, int l, int m){
    int a = pm(m, n);
    int b = (pm(m, l + 1) - pv[l][m - 1]) % MOD;
    int c = pm(m, l);
    int r = a * (b * mi(c) % MOD) % MOD;
    return (r + MOD) % MOD;
}

int a[L_MAX];
int dp[L_MAX][L_MAX];

void solve(){
    int n, m; cin >> n >> m;
    int k = 0; while((1LL << k + 2) - 1 <= n) k++;
    for(int i = 0; i < L_MAX; i++) a[i] = dp[k][i];
    int rem = n - (1LL << k + 1) + 1;
    for(int i = 0; i <= k; i++){
        int complete = (rem / (1LL << i + 1)) % MOD;
        int cr = (1LL << i) % MOD;
        int ra = min((rem % (1LL << i + 1)), 1LL << i) % MOD;
        int rb = max((rem % (1LL << i + 1)) - (1LL << i), 0LL) % MOD;
        a[(i + 1) * 2] = (a[(i + 1) * 2] + (complete * cr % MOD * cr % MOD + ra * rb % MOD) * 2 % MOD) % MOD;
    }
    a[0] = n % MOD;

    rem %= MOD;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= i; j++){
            a[i + j + 1] = (a[i + j + 1] + rem * ((1LL << max(0LL, j - 1)) % MOD) * 2 % MOD) % MOD;
        }
    }

    int ans = n % MOD * m % MOD * (m + 1) % MOD * mi(2) % MOD * pm(m, n - 1) % MOD;
    int mi2 = mi(2);
    for(int l = 1; l < L_MAX - 1; l++) {
        ans += f(n, l + 1, m) * a[l] % MOD * mi2 % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    for(int l = 0; l < L_MAX; l++){
        for(int m = 0; m < M_MAX; m++){
            v[l][m] = pm(m, l);
            pv[l][m] = (v[l][m] + (m > 0 ? pv[l][m - 1] : 0)) % MOD;
        }
    }
    dp[0][0] = 1;
    for(int l = 1; l <= 60; l++){
        for(int i = 0; i < L_MAX; i++) dp[l][i] = (dp[l - 1][i] * 2) % MOD;
        dp[l][0] = ((1LL << l + 1) - 1) % MOD;
        for(int i = 0; i < l; i++) dp[l][i + 1] = (dp[l][i + 1] + (1LL << i + 2)) % MOD;
        for(int i = 0; i < l; i++) for(int j = 0; j < l; j++) dp[l][i + j + 2] = (dp[l][i + j + 2] + ((1LL << i) % MOD) * ((1LL << j) % MOD) * 2) % MOD;
    }
    int t; cin >> t;
    while(t--){
        solve();
    }
}
