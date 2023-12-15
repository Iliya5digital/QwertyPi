#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 111;
int a[N], b[N];

struct Edge{
    int u, v, w;
};

vector<pair<int, int>> G[N];
bool vis[N];
void dfs(int v){
    vis[v] = true;
    for(auto [u, w] : G[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}

int n, m;
int group[N];
vector<Edge> E;
vector<pair<string, int>> ans;
int A1 = 0;
void run(){
    int k = (1LL << 60);
    for(auto& e : E){
        if(group[e.u] != group[e.v]){
            k = min(k, e.w);
        }
    }
    for(auto& e : E){
        if(group[e.u] != group[e.v]){
            e.w -= k;
        }
    }
    if(k != 0){
        string s;
        for(int i = 1; i <= n; i++){
            s.push_back('0' + (group[i] == 0));
        }
        ans.push_back({s, k});
        A1 += k;
    }
}

bool rem[N];
void solve(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        E.push_back({u, v, w});
    }
    dfs(1);
    if(!vis[n]){
        cout << "inf" << endl;
        return;
    }

    group[1] = 0; group[n] = 1;
    for(int i = 2; i <= n - 1; i++) rem[i] = true;
    while(true){
        for(int i = 1; i <= n; i++) if(rem[i]) group[i] = 0; run();
        for(int i = 1; i <= n; i++) if(rem[i]) group[i] = 1; run();
        for(int i = 1; i <= n; i++) if(rem[i]) group[i] = -1;
        bool Done = false;
        for(auto& e : E){
            if(group[e.v] == -1) swap(e.u, e.v);
            if(group[e.v] == -1 || e.w != 0) continue;
            if(group[e.u] == -1){
                group[e.u] = group[e.v];
                rem[e.u] = false;
            }else if(group[e.u] != group[e.v]){
                Done = true; break;
            }
        }
        if(Done) break;
        int s = accumulate(rem, rem + n + 1, 0LL);
        if(s == 0) break;
    }
    run();
    cout << A1 << ' ' << ans.size() << endl;
    for(auto [a, b] : ans){
        cout << a << ' ' << b << endl;
    }
}

int32_t main(){
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}
