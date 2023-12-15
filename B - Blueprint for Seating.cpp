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

const int MOD = 998244353;
const int N = 2e6 + 11;
int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}
int mi(int a){
    return pm(a, MOD - 2);
}


int f[N], fi[N];
int c(int n, int r){
    assert(n >= 0 && r <= n && r >= 0);
    return f[n] * fi[n - r] % MOD * fi[r] % MOD;
}

int gen(int pw, int r){
    if(r < 0) return 0;
    int ans = 0;
    for(int i = 0; i <= pw; i++){
        int rp = r - i * 2;
        if(rp < 0 || rp > pw - i) continue;
        ans += c(pw, i) * c(pw - i, rp) % MOD;
    }
    ans %= MOD;
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    int a = n / k / 2;
    int ans = k * (a - 1) * a + a * (n % (k * 2));
    int cnt = 0;
    if(a == 0){
        cnt = c(k - 1, n - (k + 1));
    }else{
        int r = n % (k * 2);
        cnt += 1 * gen(k - 1, r - 2);
        cnt += 2 * gen(k - 1, r - 1);
        cnt += 1 * gen(k - 1, r - 0);
        cnt %= MOD;
    }
    cout << ans << ' ' << cnt << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    f[0] = 1; for(int i = 1; i < N; i++) f[i] = f[i - 1] * i % MOD;
    fi[N - 1] = mi(f[N - 1]); for(int i = N - 2; i >= 0; i--) fi[i] = fi[i + 1] * (i + 1) % MOD;
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
