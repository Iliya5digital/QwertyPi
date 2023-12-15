#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int a[200011];

struct DSU{
    int par[200011], sz[200011]; priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> S[200011];
    void init(int n){
        for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
        for(int i = 0; i < n; i++) { while(!S[i].empty()) S[i].pop(); }
        for(int i = 0; i < n; i++) S[i].push({a[i], i});
    }
    int f(int x){
        if(x == par[x]) return x;
        return par[x] = f(par[x]);
    }
    void g(int x, int y){
        x = f(x), y = f(y);
        if(x == y) return;
        if(S[x].size() < S[y].size()) swap(x, y);
        while(!S[y].empty()) S[x].push(S[y].top()), S[y].pop();
        sz[x] += sz[y];
        par[y] = x;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& getSet(int x){
        return S[f(x)];
    }
} dsu;

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i]; a[n] = 0;
    dsu.init(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        dsu.S[v].push({a[u], u});
        dsu.S[u].push({a[v], v});
    }

    vector<int> cur, nxt;
    for(int i = 0; i < n; i++) if(a[i] == 0) cur.push_back(i);
    while(cur.size()){
        for(auto v : cur){
            while(!dsu.getSet(v).empty() && dsu.sz[dsu.f(v)] >= dsu.getSet(v).top().fi){
                int u = dsu.getSet(v).top().se;
                dsu.getSet(v).pop();
                dsu.g(v, u);
                nxt.push_back(u);
            }
        }
        swap(cur, nxt); nxt.clear();
    }
    if(n == 1){
        cout << (a[0] == 0 ? "YES" : "NO") << endl;
    }else{
        cout << (dsu.sz[dsu.f(0)] == n ? "YES" : "NO") << endl;
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
}
