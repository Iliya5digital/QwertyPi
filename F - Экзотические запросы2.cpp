#include <bits/stdc++.h>
 
using namespace std;
 
const int N_MAX = 1e6 + 11;
 
int a[N_MAX];
vector<int> p[N_MAX];
int ps[N_MAX];
int n, q; 
 
struct SegTree{
    int t[N_MAX << 2] = {};
    void update(int qi, int qv, int v = 0, int l = 0, int r = n){
        if(l == r) t[v] = qv;
        else {
            int m = (l + r) / 2;
            if(qi <= m) update(qi, qv, v * 2 + 1, l, m);
            else update(qi, qv, v * 2 + 2, m + 1, r);
            t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
    int range_max(int ql, int qr, int v = 0, int l = 0, int r = n){
        if(qr < l || r < ql || ql > qr) return 0;
        if(ql <= l && r <= qr) return t[v];
        int m = (l + r) / 2;
        return max(range_max(ql, qr, v * 2 + 1, l, m),
                   range_max(ql, qr, v * 2 + 2, m + 1, r));
    }
} ST;
 
struct point{
    int x, y;
};
 
struct node{
    int s = 0;
    node *ll, *rr;
    node() : ll(nullptr), rr(nullptr){};
    node(int s) : s(s), ll(nullptr), rr(nullptr){};
};
 
node* roots[N_MAX];
 
node* build(int l = 0, int r = n){
    if(l == r) return new node(0);
    int m = (l + r) / 2;
    node *vl = build(l, m);
    node *vr = build(m + 1, r);
    node *res = new node();
    res->ll = vl; res->rr = vr;
    return res;
}
 
node* add(node* v, int qi, int qv, int l = 0, int r = n){
    if(l == r) return new node(qv + v->s);
    int m = (l + r) / 2;
    node *vl, *vr;
    if(qi <= m){
        vl = add(v->ll, qi, qv, l, m);
        vr = v->rr;
    }else{
        vl = v->ll;
        vr = add(v->rr, qi, qv, m + 1, r);
    }
    node *res = new node();
    res->s = vl->s + vr->s;
    res->ll = vl; res->rr = vr;
    return res;
}
 
int sum(node* v, int qr, int l = 0, int r = n){
    if(qr < l) return 0;
    if(l == r) return v->s;
    int m = (l + r) / 2;
    if(qr <= m) return sum(v->ll, qr, l, m);
    else return sum(v->rr, qr, m + 1, r) + v->ll->s;
}
 
int count_element(int l, int r){
    return ps[r] - ps[l - 1];
}
 
int count_extra(int l, int r){
    return sum(roots[r], l - 1) - sum(roots[l - 1], l - 1);
}
 
int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        p[a[i]].push_back(i);
    }
    vector<point> b;
    for(int i = 1; i <= n; i++){
        ps[i] = p[i].size() + ps[i - 1];
        for(int j = 0; j + 1 < p[i].size(); j++){
            int mx = ST.range_max(p[i][j] + 1, p[i][j + 1] - 1);
            b.push_back({i, mx});
        }
        for(auto j : p[i]){
            ST.update(j, i);
        }
    }
    sort(b.begin(), b.end(), [](point a, point b){
        return a.x < b.x;
    });
 
    roots[0] = build(); int bi = 0;
    for(int i = 1; i <= n; i++){
        roots[i] = roots[i - 1];
        while(bi < b.size() && b[bi].x == i){
            roots[i] = add(roots[i], b[bi].y, 1);
            bi++;
        }
    }
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        int a = count_element(l, r);
        int b = count_extra(l, r);
        cout << a - b << '\n';
    }
}
