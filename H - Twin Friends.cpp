#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

const int N = 2e5 + 11;
int f[N], fi[N];

int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}
int mi(int a){
    return pm(a, MOD - 2);
}

int dp[27][N], dp2[27][N];
void solve(){
    f[0] = 1; for(int i = 1; i < N; i++) f[i] = f[i - 1] * i % MOD;
    fi[0] = 1; for(int i = 1; i < N; i++) fi[i] = mi(f[i]);

    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int a[27] = {}, b[27] = {};
    for(auto c : s) a[c - 'A']++;
    for(auto c : t) b[c - 'A']++;

    int Part_A = f[n]; for(int i = 0; i < 26; i++) Part_A = Part_A * fi[a[i]] % MOD;
    fill(dp2[0], dp2[0] + N, 1);
    for(int i = 1; i <= 26; i++){
        for(int j = 0; j <= a[i - 1]; j++){
            if(b[i - 1] < j) continue;
            int mul = f[a[i - 1]] * fi[j] % MOD * fi[a[i - 1] - j] % MOD;
            dp[i][j] = mul * dp2[i - 1][j] % MOD;
            if(b[i] < a[i - 1] - j) continue;
            dp2[i][b[i] - (a[i - 1] - j)] = dp[i][j];
        }
        for(int j = b[i] - 1; j >= 0; j--){
            dp2[i][j] = (dp2[i][j + 1] + dp2[i][j]) % MOD;
        }
    }
    /*
    for(int i = 0; i <= 26; i++){
        for(int j = 0; j < n; j++){
            cout << dp2[i][j] << ' ';
        }
        cout << "| ";
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    int Part_B = dp2[26][0];

    int ans = Part_A * Part_B % MOD;
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
