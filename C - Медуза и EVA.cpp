#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5001 + 11;
vector<int> G[N];
long double dp[N];
long double dp2[N][N];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        G[i].clear();
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        vector<int> s = G[i];
        vector<long double> P;
        for(auto v : s){
            P.push_back(dp[v]);
        }
        sort(P.begin(), P.end(), [](auto a, auto b){ return a > b; });
        dp[i] = 0;
        for(int j = 0; j < P.size(); j++){
            dp[i] += P[j] * dp2[P.size()][j];
        }
    }
    cout << setprecision(10) << fixed << dp[1] << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    dp2[1][0] = 1;
    dp2[2][0] = 0.5, dp2[2][1] = 0;
    for(int n = 3; n < N; n++){
        dp2[n][0] = 1.0 / n;
        for(int i = 1; i < n; i++){
            if(i >= 2) dp2[n][i] += (i - 1) * dp2[n - 2][i - 2];
            dp2[n][i] += (n - 2 - (i - 1)) * dp2[n - 2][i - 1];
            dp2[n][i] /= n;
        }
    }
    int t; cin >> t;
    while(t--){
        solve();
    }
}
