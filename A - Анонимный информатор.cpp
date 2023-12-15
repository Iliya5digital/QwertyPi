#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

typedef long long ll;

using namespace std;

const int N = 2e5 + 11;

int b[N];
bool vis[N];
vector<int> G[N];
bool has_cycle = false;
int max_d = 0;
void dfs(int v){
    vis[v] = true;
    for(auto u : G[v]){
        if(vis[u]) has_cycle = true; 
        if(has_cycle) return;
        dfs(u);
    }
}
int dp[N];
int c[N];
void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> b[i];
    fill(vis, vis + n + 1, false); has_cycle = false;
    for(int i = 0; i <= n; i++) G[i].clear();
    for(int i = 1; i <= n; i++){
        if(b[i] < 1 || b[i] > n) continue;
        int d = (i - b[i] + n) % n;
        G[(d + b[i]) % n].push_back(d);
    }
    dfs(0);
    if(has_cycle){
        cout << "Yes" << '\n';
        return;
    }
    dp[0] = 0;
    fill(c, c + n, 0);
    for(int i = 0; i < n; i++){
        for(auto u : G[i]) c[u]++;
    }

    fill(vis, vis + n, 0);
    fill(dp, dp + n, -(1 << 30)); dp[0] = 0;
    vector<int> dq;
    for(int i = 0; i < n; i++){
        if(c[i] == 0) dq.push_back(i);
    }
    while(dq.size()){
        int v = dq.back(); dq.pop_back();
        for(auto u : G[v]){
            dp[u] = max(dp[u], dp[v] + 1);
            c[u]--; if(c[u] == 0) dq.push_back(u);
        }
    }
    int mx = *max_element(dp, dp + n);
    cout << (k <= mx ? "Yes" : "No") << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        #ifdef LOCAL
            cerr << "************ Case #" << t << " ************" << '\n';
        #endif
        solve();
    }
}
