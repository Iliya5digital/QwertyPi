#include <bits/stdc++.h>

#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define forn(i, n) for(int i = 0; i < (n); i++)

typedef long double LD;
typedef long long ll;

const int INF = 1LL << 60;
const LD eps = 1e-9;

using namespace std;

const int N = 1e3 + 11;
const int M = 1e5 + 11;
struct DSU{
    int dsu[N];
    void init(int n){ for(int i = 0; i <= n; i++) dsu[i] = i; }
    int f(int x){ return x == dsu[x] ? x : dsu[x] = f(dsu[x]); }
    void g(int x, int y) { dsu[f(x)] = f(y); }
} dsu;

vector<int> group[N], G[N];
bool FAILED;
bool vis[N];
int deg[N]; bool in_V[N], in_queue[N];

vector<int> tp; bool can_tp;
vector<pair<int, int>> ans;
void topo_sort(int v){
    in_queue[v] = vis[v] = true;
    for(auto u : G[v]){
        if(!in_V[u]) continue;
        if(in_queue[u]) can_tp = false;
        if(vis[u]) continue;
        topo_sort(u);
    }
    tp.push_back(v);
    in_queue[v] = false;
}

bool real_tp_sort(vector<int>& V){
    can_tp = true; tp.clear();
    for(auto v : V) vis[v] = in_queue[v] = false;
    for(auto v : V) if(in_V[v] && !vis[v]) topo_sort(v);
    reverse(tp.begin(), tp.end());
    return can_tp;
}

void calc(vector<int> V){
    // for(auto v : V) cout << v << ' '; cout << '\n';
    if(V.empty()) return;

    for(auto v : V) in_V[v] = true;
    {
        bool ok = real_tp_sort(V);
        if(ok){
            for(int i = 0; i + 1 < tp.size(); i++){
                ans.push_back({tp[i], tp[i + 1]});
            }
            return;
        }
    }

    for(auto v : V){
        in_V[v] = false;

        bool ok = real_tp_sort(V);
        if(ok){
            ans.push_back({v, tp.front()});
            for(int i = 0; i + 1 < tp.size(); i++){
                ans.push_back({tp[i], tp[i + 1]});
            }
            ans.push_back({tp.back(), v});
            return;
        }
        in_V[v] = true;
    }

    FAILED = true;
}

struct Edge{
    int u, v;
} E[M];

void solve(){
    int n, m; cin >> n >> m;
    dsu.init(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        E[i] = {u, v};
        dsu.g(u, v); G[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++){
        group[dsu.f(i)].push_back(i);
    }

    ans.clear(); FAILED = false;
    for(int i = 1; i <= n; i++){
        calc(group[i]);
    }

    if(!FAILED){
        cout << ans.size() << '\n';
        for(auto [a, b] : ans){
            cout << a << ' ' << b << '\n';
        }
    }else{
        cout << -1 << '\n';
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
