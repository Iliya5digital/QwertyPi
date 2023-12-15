#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 3e5 + 11;
const int K = 10;
map<pair<int, int>, int> cur, nxt;
vector<int> need[N];

int chmax(int& x, int y){ x = max(x, y); return x; }
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> U;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        U.push_back({l, i + 1});
        U.push_back({r + 1, -(i + 1)});
    }
    U.push_back({n + 1, 0});
    sort(U.begin(), U.end());
    int uid = 0; set<int> S;
    int ans = 0;
    for(int i = 1; i <= n; i++) need[i].clear();
    int id = 0;
    for(int i = 1; i <= n; i++){
        while(U[uid].fi == i){
            if(U[uid].se > 0) S.insert(U[uid].se);
            else S.erase(-U[uid].se);
            uid++;
        }
        if(S.size() == 0) ans++;
        else if(S.size() <= k){
            need[++id] = vector<int>(S.begin(), S.end());
        }
    }
    cur.clear();
    cur[{0, 0}] = 0;
    for(int i = 1; i <= id; i++){
        int x0 = need[i - 1].size(), x1 = need[i].size();
        vector<int> c;
        for(int j0 = 0; j0 < x0; j0++){
            c.push_back(-1);
            for(int j1 = 0; j1 < x1; j1++){
                if(need[i - 1][j0] == need[i][j1]){
                    c.back() = j1;
                }
            }
        }
        vector<int> d = c;
        // printf("Tran %lld to %lld\n", i - 1, i);
        // for(auto i : c) cout << i << ' '; cout << '\n';
        for(auto [a, b] : cur){
            auto [s0, c] = a;
            int s1 = 0;
            for(int x = 0; x < x0; x++){
                if(s0 & (1 << x) && d[x] != -1) s1 |= (1 << d[x]);
            }

            // choose all
            int nt = x1 - __builtin_popcount(s1);
            if(c + nt <= k) chmax(nxt[{(1 << x1) - 1, c + nt}], b + (x1 != 0));

            // choose nothing
            chmax(nxt[{s1, c}], b + (x1 != 0 && __builtin_popcount(s1) == x1));
        }
        cur.swap(nxt);
        nxt.clear();
    }
    int ans2 = 0;
    for(auto [a, b] : cur){
        ans2 = max(ans2, b);
    }
    cout << ans + ans2 << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
