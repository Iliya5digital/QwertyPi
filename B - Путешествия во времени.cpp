#include <bits/stdc++.h>

using namespace std;

// Oops

const int N = 2e5 + 11;
struct edge{
    int u, v;
};

vector<edge> E[N], E0[N];
vector<pair<int, int>> G[N], G0[N];
int d[N];

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int n, t; cin >> n >> t;
    for(int i = 1; i <= t; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int u, v; cin >> u >> v;
            E[i].push_back({u, v});
            G[u].push_back({v, i});
            G[v].push_back({u, i});
        }
    }
    int k; cin >> k;
    fill(d, d + n + 1, 1 << 30);
    d[1] = 0; for(auto [v, T] : G[1]) E0[T].push_back({1, v});
    for(int i = 1; i <= k; i++){
        int t; cin >> t;
        vector<int> ext;
        for(auto [u, v] : E0[t]){
            if(d[v] != (1 << 30)) continue;
            d[v] = i; ext.push_back(v);
        }
        E0[t].clear();
        for(auto v : ext){
            for(auto [u, T] : G[v]){
                E0[T].push_back({v, u});
            }
        }
    }
    cout << (d[n] == (1 << 30) ? -1 : d[n]) << '\n';
}
