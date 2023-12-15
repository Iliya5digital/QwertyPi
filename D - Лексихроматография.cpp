#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 11;
const int MOD = 998244353;
int a[N], nxt[N];
vector<int> v[N];
int type[N];
int id[N];

int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

int n; 
void fill_all(int x, int t){
    while(x != n) type[x] = t, t ^= 3, x = nxt[x];
}

struct DSU{
    int dsu[N << 1];
    void init(){ for(int i = 0; i < (N << 1); i++) dsu[i] = i; }
    int f(int x){ if(x == dsu[x]) return x; return dsu[x] = f(dsu[x]); }
    void g(int x, int y){ dsu[f(x)] = f(y); }
} dsu;

void g(int x, int y, bool sa){
    dsu.g(x * 2 + 0, y * 2 + !sa);
    dsu.g(x * 2 + 1, y * 2 + !(sa ^ 1));
}

struct range{
    int l, r;
};

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> s; for(int i = 0; i < n; i++) s.insert(a[i]);
    int ans = pm(2, (int) s.size() - 1);
    for(int i = 0; i < n; i++) v[a[i]].push_back(i);

    for(int i = 1; i < N; i++){
        if(v[i].size() % 2 == 1){
            cout << ans << '\n';
            return;
        }
    }

    fill(nxt, nxt + n, n);
    dsu.init();
    
    vector<range> R;
    for(int i = 1; i < N; i++){
        for(int j = 0; j + 1 < v[i].size(); j++){
            nxt[v[i][j]] = v[i][j + 1];
            g(v[i][j], v[i][j + 1], 0);
        }
        for(int j = 0; j < v[i].size(); j++){
            id[v[i][j]] = j;
        }
        for(int j = 0; j < v[i].size(); j += 2){
            R.push_back({v[i][j], v[i][j + 1]});
        }
    }

    sort(R.begin(), R.end(), [](const range& r1, const range& r2){ return r1.l < r2.l; });

    int max_r = -1;
    for(auto [l, r] : R){
        if(r < max_r){
            cout << ans << '\n';
            return;
        }
        max_r = r;
    }

    max_r = 0;

    for(int i = 0; i < R.size(); i++){
        int l = R[i].l, r = R[i].r;
        max_r = max(max_r, l + 1);
        for(int i = max_r; i < r; i++){
            bool sa = id[i] % 2 == 0;
            g(l, i, sa);
        }
        max_r = max(max_r, r);
    }

    for(int i = 0; i < n; i++){
        if(dsu.f(i * 2) == dsu.f(i * 2 + 1)){
            cout << ans << '\n';
            return;
        }
    }

    set<int> c; for(int i = 0; i < n * 2; i++) c.insert(dsu.f(i));
    ans -= pm(2, c.size() / 2 - 1);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}
