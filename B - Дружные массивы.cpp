#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int N = 2e5 + 11;
int a[N], b[N];
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int a0 = 0, a1 = 0;
    int x = 0; for(int i = 0; i < m; i++) x |= b[i];
    for(int i = 0; i < n; i++) a0 ^= (a[i] | x), a1 ^= a[i];
    if(a0 > a1) swap(a0, a1);
    cout << a0 << ' ' << a1 << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
