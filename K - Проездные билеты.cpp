#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 11;
vector<int> G[N], H[N];

bool vis[N];
bool cc[N][N];
vector<int> tp;

void dfs(int v = 1){
    vis[v] = true;
    for(auto u : G[v]){
        if(!vis[u]) dfs(u);
    }
    tp.push_back(v);
}

vector<vector<int>> ccs[N];

vector<pair<int, int>> ans;

void add_edge(int u, int v){
    ans.push_back({u, v});
    H[u].push_back(v);
    H[v].push_back(u);
}

vector<int> Li;
void dfs2(int rt, int v){
    Li.push_back(v); vis[v] = true;
    for(auto u : H[v]){
        if(!vis[u]) dfs2(rt, u);
    }
}

map<pair<string, string>, int> mp;

int32_t main(){
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    string prv = "";
    for(int i = 0; i < n; i++){
        string s, t; cin >> s >> t;
        int cost = s == prv ? b : a;
        prv = t;
        if(s > t) swap(s, t);
        mp[{s, t}] += cost;
    }

    vector<int> v;
    for(auto [a, b] : mp) v.push_back(b);

    sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

    int total = 0;
    for(auto b : v) total += b;
    int ans = total;
    for(int i = 0; i < min((int) v.size(), k); i++){
        total += f; total -= v[i];
        ans = min(ans, total);
    }
    cout << ans << endl;
}
