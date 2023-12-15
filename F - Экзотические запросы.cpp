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
 
struct BIT2D{
    vector<int> sp[N_MAX];
    vector<int> bit[N_MAX];
    void sp_add(point p){
        p.x++; p.y++;
        for(int i = p.x; i < N_MAX; i += i & -i){
            sp[i].push_back(p.y);
        }
    }
    void init(){
        for(int i = 0; i < N_MAX; i++){
            sp[i].push_back(0);
            sort(sp[i].begin(), sp[i].end());
            sp[i].resize(unique(sp[i].begin(), sp[i].end()) - sp[i].begin());
            bit[i].resize(sp[i].size());
        }
    }
    void r_add(point p){
        int x = ++p.x, _y = ++p.y;
        for(int i = x; i < N_MAX; i += i & -i){
            int y = lower_bound(sp[i].begin(), sp[i].end(), _y) - sp[i].begin();
            for(int j = y; j < sp[i].size(); j += j & -j){
                bit[i][j]++;
            }
        }
    }
    int qry(int x, int _y){
        x++, _y++; int ret = 0;
        for(int i = x; i; i -= i & -i){
            int y = --upper_bound(sp[i].begin(), sp[i].end(), _y) - sp[i].begin();
            for(int j = y; j; j -= j & -j){
                ret += bit[i][j];
            }
        }
        return ret;
    }
} bit2d;
 
int count_element(int l, int r){
    return ps[r] - ps[l - 1];
}
 
int count_extra(int l, int r){
    return bit2d.qry(r, l - 1) - bit2d.qry(l - 1, l - 1);
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
    for(auto& p : b){
        bit2d.sp_add(p);
    }
    bit2d.init();
    for(auto& p : b){
        bit2d.r_add(p);
    }
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        int a = count_element(l, r);
        int b = count_extra(l, r);
        cout << a - b << '\n';
    }
}
