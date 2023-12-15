#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 11;
set<int> G[MAXN];
int dep[MAXN], p[MAXN];
void add_edge(int u, int v){
    G[u].insert(v); G[v].insert(u);
}

int tin[MAXN], tout[MAXN], t = 0;
void dfs(int v, int pa = -1){
    tin[v] = ++t;
    for(auto u : G[v]){
        if(u != pa){
            dep[u] = dep[v] + 1; p[u] = v; dfs(u, v);
        }
    }
    tout[v] = t;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int32_t main(){
    int n, m; cin >> n >> m;
    add_edge(0, 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }
    dfs(0);
    for(int i = 0; i < m; i++){
        int k; cin >> k; vector<int> v;
        for(int j = 0; j < k; j++){
            int l; cin >> l; v.push_back(p[l]);
        }
        set<int> s {v.begin(), v.end()};
        v = vector<int> {s.begin(), s.end()};
        bool failed = false;
        sort(v.begin(), v.end(), [](int a, int b){ return dep[a] < dep[b]; });
        for(int i = 1; i < v.size(); i++){
            if(!is_anc(v[i - 1], v[i])){
                failed = true;
            }
        }
        cout << (failed ? "NO" : "YES") << endl;
    }
}
