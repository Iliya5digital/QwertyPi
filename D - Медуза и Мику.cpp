#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3001 + 11;

int n, m;
double dp[N][N];
void solve(){
    cin >> n >> m;
    double ans = n;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = 1E9;
    for(int i = 1; i <= m; i++) dp[1][i] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int d = 1; d <= (m + n - i) / (n - i + 1) && d + j <= m; d++){
                dp[i][d + j] = min(dp[i][d + j], dp[i - 1][j] + (double) j / d);
            }
        }
    }
    cout << setprecision(10) << fixed << n + dp[n][m] * 2 << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}
