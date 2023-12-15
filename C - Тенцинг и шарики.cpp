#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 11;
int a[N];
map<int, vector<int>> M;

int nxt[N], dp[N][2];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    M.clear();
    for(int i = 0; i < n; i++){
        M[a[i]].push_back(i);
    }
    fill(nxt, nxt + n + 2, n + 1);
    for(auto [a, b] : M){
        for(int i = 1; i < (int) b.size(); i++){
            nxt[b[i - 1]] = b[i];
        }
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = dp[i][1] = 0;
    }
    for(int i = 0; i < n; i++){
        dp[nxt[i]][1] = max(dp[nxt[i]][1], max(dp[i][0], dp[i][1]) + (nxt[i] - i));
        dp[i + 1][0] = max(dp[i][0], (dp[i][1] == 0 ? 0 : dp[i][1] + 1));
    }
    cout << dp[n][0] << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
