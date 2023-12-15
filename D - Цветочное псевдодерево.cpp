#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#define fi first
#define se second
#define int long long
using namespace std;

const int N_MAX = 1e6 + 11;
int d[N_MAX];
bool sp[N_MAX];

struct edge{
    int u, v;
};

vector<edge> E;

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];
    fill(sp, sp + n + 1, 0);
    for(int i = 1; i <= n; i++) if(d[i] >= 2) sp[i] = true;
    int s = accumulate(d + 1, d + n + 1, 0LL);
    if(s != n * 2){
        cout << "No" << endl;
        return;
    }
    bool all_two = true;
    for(int i = 1; i <= n; i++) all_two &= d[i] == 2;
    if(all_two){
        cout << "Yes" << endl;
        for(int i = 1; i <= n - 1; i++){
            cout << i << ' ' << i + 1 << '\n';
        }
        cout << n << ' ' << 1 << '\n';
        return;
    }
    vector<pair<int, int>> deg;
    for(int i = 1; i <= n; i++){
        deg.push_back({d[i], i});
    }
    sort(deg.begin(), deg.end(), [](const pair<int, int>& a, const pair<int, int>& b){ return a > b; });
    E.clear();
    int c2 = 0; while(deg[c2].fi >= 3) c2++;
    int c1 = 0; while(deg[c1].fi >= 2) c1++;
    if(c2 == 1){
        cout << "No" << endl;
        return;
    }else if(c1 == c2){
        for(int i = 0; i < c1; i++){
            E.push_back({deg[i].se, deg[(i + 1) % c1].se});
        }
    }else if(c1 % 2 == 0){
        E.push_back({deg[0].se, deg[1].se});
        E.push_back({deg[1].se, deg[0].se});
        for(int i = 2; i < c1 / 2 * 2; i++){
            E.push_back({deg[i].se, deg[i - 2].se});
        }
    }else if(c2 == 2 || deg[0].fi >= 4){
        if(c2 == 2 && deg[0].fi == 3 && deg[1].fi == 3 && c1 % 2 == 1 || c2 == 2 && c1 == 3){
            cout << "No" << endl;
            return;
        }
        E.push_back({deg[0].se, deg[1].se});
        E.push_back({deg[1].se, deg[0].se});
        for(int i = 2; i < c1 / 2 * 2; i++){
            E.push_back({deg[i].se, deg[i - 2].se});
        }
        if(c1 % 2 == 1) E.push_back({deg[0].se, deg[c1 - 1].se});
    }else if(c2 == 3 && c1 == 5 || c2 == 4 && c1 == 5){
        cout << "No" << endl;
        return;
    }else{
        E.push_back({deg[0].se, deg[1].se});
        E.push_back({deg[1].se, deg[0].se});
        for(int i = 2; i < c1 / 2 * 2; i++){
            E.push_back({deg[i].se, deg[i - 2].se});
        }
        if(c1 % 2 == 1) E.push_back({deg[2].se, deg[c1 - 1].se});
    }

    for(auto [u, v] : E) d[u]--, d[v]--;
    for(int i = 1; i <= n; i++){
        while(sp[i] && d[i] > 0){
            E.push_back({i, deg[c1++].se});
            d[i]--;
        }
    }

    cout << "Yes" << endl;
    for(auto [u, v] : E){
        cout << u << ' ' << v << endl;
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
