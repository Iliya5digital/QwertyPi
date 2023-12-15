#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

const int N = 1e5 + 11;

struct node{
    int s = 0, pf = 0, sf = 0, mx = 0;
    node() = default;
    node(int v){
        s = pf = sf = mx = v;
    }
};

node operator+ (const node& a, const node& b) {
    if(a.s == INF || b.s == INF) return a.s != INF ? a : b;
    node c;
    c.s = a.s + b.s;
    c.pf = max(a.pf, a.s + b.pf);
    c.sf = max(b.sf, b.s + a.sf);
    c.mx = max({a.sf, b.pf, a.sf + b.pf, a.mx, b.mx});
    return c;
}

struct SegTree{
    node t[N << 2];
    void upd(int qi, int qv, int v, int l, int r){
        // if(v == 0) printf("UPDATE %lld %lld %lld %lld %lld\n", qi, qv, v, l, r);
        if(l == r) t[v] = qv;
        else {
            int m = (l + r) / 2;
            if(qi <= m) upd(qi, qv, v * 2 + 1, l, m);
            else upd(qi, qv, v * 2 + 2, m + 1, r);
            t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        }
    }
    node qry(int ql, int qr, int v, int l, int r){
        // if(v == 0) printf("QUERY %lld %lld\n", ql, qr);
        if(qr < l || r < ql) return INF;
        if(ql <= l && r <= qr) return t[v];
        int m = (l + r) / 2;
        node a = qry(ql, qr, v * 2 + 1, l, m);
        node b = qry(ql, qr, v * 2 + 2, m + 1, r);
        return a + b;
    }
} ST;

struct operation{
    int L, R, X, ID;
};

int ans[N];
struct query{
    int K, S, T, ID;
    bool operator< (const query& o) const {
        return K < o.K;
    }
};

void solve(){
    vector<operation> OP;
    vector<query> Q;

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int l, r, x; cin >> l >> r >> x;
        OP.push_back({l, r, x});
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int k, s, t; cin >> k >> s >> t;
        Q.push_back({k, s, t, i});
    }

    sort(all(Q));

    vector<pair<pii, int>> updates;
    for(int i = 0; i < m; i++){
        updates.push_back({{OP[i].L, OP[i].X}, i + 1});
        updates.push_back({{OP[i].R + 1, 0}, i + 1});
    }
    sort(all(updates));

    int uid = 0;
    for(int i = 0; i < q; i++){
        while(uid < updates.size() && updates[uid].fi.fi <= Q[i].K) ST.upd(updates[uid].se, updates[uid].fi.se, 0, 1, m), ++uid;
        node res = ST.qry(Q[i].S, Q[i].T, 0, 1, m);
        ans[Q[i].ID] = res.mx;
    }

    for(int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
