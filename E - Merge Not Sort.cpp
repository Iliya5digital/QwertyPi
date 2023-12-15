#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

const int N = 2000 + 11;
int c[N];
struct DSU{
    int dsu[N];
    void init(){
        for(int i = 0; i < N; i++) dsu[i] = i;
    }
    int f(int x){
        return x == dsu[x] ? x : dsu[x] = f(dsu[x]);
    }
    void g(int x, int y){
        dsu[f(x)] = f(y);
    }
} dsu;

bool dp[N]; int bk[N];
int sz[N];

bool in[N];
int l[N], r[N];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n * 2; i++) cin >> c[i];
    dsu.init();

    for(int i = 0; i < n * 2; i++){
        l[i] = max(i - 1, 0LL);
        r[i] = i + 1;
    }
    auto rem = [&](int x){
        l[r[x]] = l[x];
        r[l[x]] = r[x];
    };

    for(int tr = 0; tr < n * 2; tr++){
        int x = 0;
        while(r[x] != n * 2){
            if(c[x] > c[r[x]]){
                dsu.g(x, r[x]);
                rem(r[x]);
                break;
            }
            x = r[x];
        }
    }
    for(int i = 0; i < n * 2; i++) sz[dsu.f(i)]++;

    dp[0] = true;
    for(int i = 0; i < n * 2; i++){
        if(dsu.f(i) != i) continue;
        for(int j = n * 2 - sz[i]; j >= 0; j--){
            if(dp[j] && !dp[j + sz[i]]){
                dp[j + sz[i]] = true;
                bk[j + sz[i]] = i;
            }
        }
    }
    for(int i = 0; i < n * 2; i++){
        if(dsu.f(i) != i) continue;
    }

    if(!dp[n]){
        cout << -1 << '\n';
        return;
    }

    int x = n;
    while(x != 0){
        int y = bk[x];
        in[y] = true;
        x -= sz[y];
    }
    for(int i = 0; i < n * 2; i++){
        if(in[dsu.f(i)]) in[i] = true;
    }

    for(int i = 0; i < n * 2; i++){
        if(in[i]) cout << c[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n * 2; i++){
        if(!in[i]) cout << c[i] << ' ';
    }
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
