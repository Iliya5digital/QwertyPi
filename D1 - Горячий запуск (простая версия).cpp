#include <bits/stdc++.h>
#define int long long
#define INF (1LL << 60)
using namespace std;

int a[300011];
int h[300011], c[300011];
int dp[300011];
int pv[300011], ex[300011];
int nat[300011], snat[300011];

struct DSU{
    int dsu[300011];
    void init(int n){ for(int i = 0; i <= n; i++) dsu[i] = i; }
    int f(int x){ return x == dsu[x] ? x : dsu[x] = f(dsu[x]); }
    void g(int x, int y){ dsu[f(y)] = f(x); }
} dsu;

void solve(){
    int n, k; cin >> n >> k;
    dsu.init(n);
    fill(pv, pv + n, -1);
    fill(ex, ex + k, -1);
    fill(dp + 1, dp + n + 1, INF);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
    }
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]) dsu.g(i, i + 1);
    }
    for(int i = 0; i < n; i++){
        pv[i] = ex[a[i]];
        ex[a[i]] = i;
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
    }
    for(int i = 0; i < k; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        nat[i] = (i == 0) ? c[a[i]] : (a[i] == a[i - 1] ? h[a[i]] : c[a[i]]);
        snat[i + 1] = snat[i] + nat[i];
    }
    for(int i = 0; i < n; i++){
        dp[i + 1] = dp[i] + nat[i];
        if(pv[i] != -1 && pv[i] != i - 1) dp[i + 1] = min(dp[i + 1], dp[pv[i] + 2] + snat[i] - snat[pv[i] + 2] + h[a[i]]);
    }
    cout << dp[n] << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
