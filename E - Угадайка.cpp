#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N_MAX = 2e5 + 11;
const int MOD = 998244353;

int s[N_MAX];

int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

int mi(int a){
    return pm(a, MOD - 2);
}

int calc(int lv, int l, int r, int base){
    if(lv == -1) return base * (r - l) * (r - l);
    int m = l; while(m < r && !(s[m] & (1 << lv))) m++;
    int p1 = 0, p2 = 0, p3 = 0;
    if(l != m) p1 = calc(lv - 1, l, m, base);
    if(m != r) p2 = calc(lv - 1, m, r, base + 1);
    p3 = base * (m - l) * (r - m) * 2 + (m - l) * (r - m);
    return (p1 + p2 + p3) % MOD;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    int ans = calc(29, 0, n, 1);
    ans = (ans * mi(n) % MOD * mi(n) % MOD);
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
