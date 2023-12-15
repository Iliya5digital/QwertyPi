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

const int N = 2e5 + 11;
int a[N];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s = accumulate(a, a + n, 0LL);
    int ans = min(s / 3, s - a[n - 1]);
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
