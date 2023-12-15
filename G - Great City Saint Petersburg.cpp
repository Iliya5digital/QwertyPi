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

const int N = 2e5 + 11;
int n;

struct node{
    node() : min(-INF), max(-INF), sum(0) {};
    int l, r, min, max, sum;
};

struct Tag{
    Tag() : op(0) {};
    Tag(int op, int val) : op(op), val(val){};
    int op, val;
};

const int CHMAX = 1;
const int ADD = 2;

void operator+= (node& v, const Tag& t){
    if(t.op == CHMAX){
        v.min = v.max = t.val;
        v.sum = t.val * (v.r - v.l + 1);
    }else{
        v.min += t.val, v.max += t.val;
        v.sum += (v.r - v.l + 1) * t.val;
    }
}

void operator+= (Tag& t1, const Tag& t2){
    if(t1.op == 0){
        t1 = t2;
    }else if(t2.op == CHMAX){
        if(t1.op == CHMAX){
            t1.val = max(t1.val, t2.val);
        }else{
            t1 = t2;
        }
    }else if(t2.op == ADD){
        t1.val += t2.val;
    }
}
node operator+ (const node& a, const node& b){
    if(a.l == -1 || b.l == -1) return a.l != -1 ? a : b;
    node c; c.l = a.l, c.r = b.r;
    c.min = min(a.min, b.min);
    c.max = max(a.max, b.max);
    c.sum = a.sum + b.sum;
    return c;
}

struct SegTree{
    vector<node> t; vector<Tag> tag;

    void push_down(int v){
        if(tag[v].op == 0) return;
        t[v * 2 + 1] += tag[v];
        tag[v * 2 + 1] += tag[v];
        t[v * 2 + 2] += tag[v];
        tag[v * 2 + 2] += tag[v];
        tag[v].op = 0;
    }

    void build(int v = 0, int l = 1, int r = n){
        if(v == 0) t.resize(1 << 19), tag.resize(1 << 19);
        t[v].l = l, t[v].r = r;
        if(l != r){
            int m = (l + r) / 2;
            build(v * 2 + 1, l, m);
            build(v * 2 + 2, m + 1, r);
        }
    }

    void chmax(int ql, int qr, int qv, int v = 0, int l = 1, int r = n){
#ifdef LOCAL
        if(v == 0) cout << "CHMAX " << ql << ' ' << qr << ' ' << qv << ' ' << t[v].min << ' ' << t[v].max << endl;
#endif
        if(qr < l || r < ql || qr < ql) return;
        if(qv <= t[v].min) return;
        if(ql <= l && r <= qr && qv >= t[v].max) {
            t[v] += Tag(CHMAX, qv);
            tag[v] += Tag(CHMAX, qv); 
            return;
        }
        int m = (l + r) / 2; push_down(v);
        chmax(ql, qr, qv, v * 2 + 1, l, m);
        chmax(ql, qr, qv, v * 2 + 2, m + 1, r);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
    void add(int ql, int qr, int qv, int v = 0, int l = 1, int r = n){
#ifdef LOCAL
        if(v == 0) cout << "ADD " << ql << ' ' << qr << ' ' << qv << endl;
#endif
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            t[v] += Tag(ADD, qv);
            tag[v] += Tag(ADD, qv);
            return;
        }
        int m = (l + r) / 2; push_down(v);
        add(ql, qr, qv, v * 2 + 1, l, m);
        add(ql, qr, qv, v * 2 + 2, m + 1, r);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        // cout << v << ' ' << t[v].min << ' ' << t[v].max << ' ' << t[v].sum << endl;
    }
    int bs(int ql, int qr, int qv, int v = 0, int l = 1, int r = n){
        if(qr < l || r < ql || t[v].max < qv) return INF;
        if(l == r) { return t[v].max >= qv ? l : INF; }
        int m = (l + r) / 2; push_down(v);
        int ans = bs(ql, qr, qv, v * 2 + 1, l, m);
        if(ans != INF) return ans;
        ans = bs(ql, qr, qv, v * 2 + 2, m + 1, r);
        return ans;
    }
    int qry(int ql, int qr, int v = 0, int l = 1, int r = n){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[v].sum;
        int m = (l + r) / 2; push_down(v);
        int a = qry(ql, qr, v * 2 + 1, l, m);
        int b = qry(ql, qr, v * 2 + 2, m + 1, r);
        return a + b;
    }
    int qry_max(int ql, int qr, int v = 0, int l = 1, int r = n){
        if(qr < l || r < ql || qr < ql) return -INF;
        if(ql <= l && r <= qr) return t[v].max;
        int m = (l + r) / 2; push_down(v);
        int a = qry_max(ql, qr, v * 2 + 1, l, m);
        int b = qry_max(ql, qr, v * 2 + 2, m + 1, r);
        return max(a, b);
    }
} L, LM, R, RM;

int a[N], s;

void init(){
    L.build(); LM.build();
    R.build(); RM.build();
    for(int i = 1; i <= n; i++){
        L.chmax(i, i, a[i]); LM.chmax(i, n, a[i]);
        R.chmax(n + 1 - i, n + 1 - i, a[i]); RM.chmax(n + 1 - i, n, a[i]);
    }
}

void add(SegTree& L, SegTree& LM, int l, int r){
    int mx, pos;
    L.add(l, r, 1);
    mx = L.qry_max(1, l - 1);
    pos = L.bs(l, r, mx + 1); 
    if(pos != INF) LM.add(pos, r, 1); 
    mx = LM.qry_max(l, r); 
    LM.chmax(r + 1, n, mx); 
}

void upd(int l, int r){
    add(L, LM, l, r);
    add(R, RM, n + 1 - r, n + 1 - l);
}

int qry(){
    int A = LM.qry(1, n);
    int B = RM.qry(1, n);
    int C = L.qry_max(1, n) * n;
    int D = s;
#ifdef LOCAL
    cout << "VALIDATE " << A << ' ' << B << ' ' << C << ' ' << D << endl;
#endif
    return A + B - C - D;
}

void solve(){
    cin >> n; int q; cin >> q; 
    for(int i = 1; i <= n; i++) cin >> a[i]; s = accumulate(a + 1, a + n + 1, 0LL);
    init();
    cout << qry() << '\n';
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        upd(l, r); 
        s += r - l + 1;
        cout << qry() << '\n';
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
