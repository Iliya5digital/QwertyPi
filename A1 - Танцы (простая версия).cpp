#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 11;
int a[N], b[N];

int n, m;

struct SegTree{
    int t[N << 2];
    void upd(int qi, int qv, int v = 0, int l = 0, int r = N - 1){
        if(l == r) t[v] = qv;
        else {
            int m = (l + r) / 2;
            if(qi <= m) upd(qi, qv, v * 2 + 1, l, m);
            else upd(qi, qv, v * 2 + 2, m + 1, r);
            t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
    int qry(int ql, int qr, int v = 0, int l = 0, int r = N - 1){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[v];
        else {
            int m = (l + r) / 2;
            return max(qry(ql, qr, v * 2 + 1, l, m)
            , qry(ql, qr, v * 2 + 2, m + 1, r));
        }
    }
} ST;

int qry(){
    int lo = 0, hi = n;
    while(lo != hi){
        int mid = (lo + hi + 1) / 2;
        if(ST.qry(0, mid - 1) <= n - mid){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    return n - lo;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a + 1, a + n); sort(b, b + n);
    for(int i = 1; i < n; i++) a[i] = upper_bound(b, b + n, a[i]) - b;
    int ans = 0;
    for(int i = 1; i < n; i++) ST.upd(i, a[i] - i);
    int ai = 1;
    for(int i = 0; i <= n; i++){
        while(ai < n && i > a[ai]){
            ST.upd(ai - 1, a[ai] - (ai - 1));
            ai++;
        }
        int l = i == 0 ? 1 : b[i - 1];
        int r = min(m, i == n ? m : b[i] - 1);
        if(l > r) continue;
        int mul = r - l + 1;
        ST.upd(ai - 1, i - (ai - 1));
        ans += mul * qry();
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
