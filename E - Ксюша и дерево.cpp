#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 11;
const int LGN = 20;
bool done[MAXN];
vector<int> G[MAXN];
int lv[MAXN], sz[MAXN], rt[MAXN][LGN], d[MAXN][LGN], dp[MAXN];

void find_subtree_size(int v, int pa = -1){
    sz[v] = 1;
    for(auto u : G[v]){
        if(!done[u] && u != pa){
            find_subtree_size(u, v);
            sz[v] += sz[u];
        }
    }
}

int find_centroid(int v, int n, int pa = -1){
    for(auto u : G[v]){
        if(!done[u] && u != pa && sz[u] > n / 2){
            return find_centroid(u, n, v);
        }
    }
    return v;
}

void calc(int c, int v, int level, int depth = 0, int pa = -1){
    rt[v][level] = c;
    d[v][level] = depth;
    for(auto u : G[v]){
        if(!done[u] && u != pa){
            calc(c, u, level, depth + 1, v);
        }
    }
}

void centroid_decomposition(int v, int pa = -1, int level = 0){
    if(done[v]) return;
    find_subtree_size(v, pa);
    int c = find_centroid(v, sz[v], pa);
    calc(c, c, level);
    done[c] = true; lv[c] = level;
    for(auto u : G[c]){
        centroid_decomposition(u, c, level + 1);
    }
}

void paint_red(int v){
    for(int i = lv[v]; i >= 0; i--){
        if(rt[v][i] == 0) continue;
        int root = rt[v][i];
        dp[root] = min(dp[root], d[v][i]);
    }
}

int query_dist(int v){
    int ans = 1 << 30;
    for(int i = lv[v]; i >= 0; i--){
        if(rt[v][i] == 0) continue;
        int root = rt[v][i];
        ans = min(ans, d[v][i] + dp[root]);
    }
    return ans;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dp, 0x3f, sizeof(dp));
    centroid_decomposition(1);
    paint_red(1);
    for(int i = 0; i < m; i++){
        int t, v; cin >> t >> v;
        if(t == 1){
            paint_red(v);
        }else{
            cout << query_dist(v) << '\n';
        }
    }
}
