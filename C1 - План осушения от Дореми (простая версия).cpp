#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 3e5 + 11;
const int K = 10;
int cur[1 << K][K + 1], nxt[1 << K][K + 1];
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
    cur[0][0] = 0; for(int j = 1; j <= k; j++) cur[0][j] = -(1LL << 60);
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
        // printf("Tran %lld to %lld\n", i - 1, i);
        // for(auto i : c) cout << i << ' '; cout << '\n';
        for(int s1 = 0; s1 < (1 << x1); s1++){
            for(int x = 0; x <= k; x++){
                nxt[s1][x] = -(1LL << 60);
            }
        }
        for(int s0 = 0; s0 < (1 << x0); s0++){
            int s1 = 0;
            for(int x = 0; x < x0; x++){
                if(s0 & (1 << x) && c[x] != -1) s1 |= (1 << c[x]);
            }

            // choose all
            int nt = x1 - __builtin_popcount(s1);
            for(int c = 0; c <= k - nt; c++){
                chmax(nxt[(1 << x1) - 1][c + nt], cur[s0][c] + (x1 != 0));
            }

            // choose nothing
            for(int c = 0; c <= k; c++){
                chmax(nxt[s1][c], cur[s0][c] + (x1 != 0 && __builtin_popcount(s1) == x1));
            }
        }
        for(int s1 = 0; s1 < (1 << x1); s1++){
            for(int c = 0; c <= k; c++){
                cur[s1][c] = nxt[s1][c];
            }
        }
    }
    int ans2 = 0;
    for(int x = 0; x < (1 << need[id].size()); x++){
        for(int y = 0; y <= k; y++){
            ans2 = max(ans2, cur[x][y]);
        }
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
