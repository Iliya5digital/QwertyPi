#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 11;
int l[N], r[N], c[N];
int s[N], dp[N];
vector<int> v[N]; int ct[N];

struct SegTree{
    int t[N << 2], lz[N << 2]; // min
    void push(int v){
        lz[v * 2 + 1] += lz[v];
        lz[v * 2 + 2] += lz[v];
        t[v * 2 + 1] += lz[v];
        t[v * 2 + 2] += lz[v];
        lz[v] = 0;
    }
    void add(int ql, int qr, int c, int v, int l, int r){
        if(ql > qr) return;
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            t[v] += c;
            lz[v] += c;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        add(ql, qr, c, v * 2 + 1, l, m);
        add(ql, qr, c, v * 2 + 2, m + 1, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
    void upd(int idx, int c, int v, int l, int r){
        if(l == r){
            t[v] = c;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        upd(idx, c, v * 2 + 1, l, m);
        upd(idx, c, v * 2 + 2, m + 1, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
    int qry(int ql, int qr, int v, int l, int r){
        if(qr < l || r < ql) return 1LL << 60;
        if(ql <= l && r <= qr) return t[v];
        push(v);
        int m = (l + r) / 2;
        int x = qry(ql, qr, v * 2 + 1, l, m);
        int y = qry(ql, qr, v * 2 + 2, m + 1, r);
        return min(x, y);
    }

    void print(int k){
        for(int i = 0; i <= k; i++){
            cout << qry(i, i, 0, 0, k) << ' ';
        }
        cout << endl;
    }
} segTree;

int32_t main(){
    int n, k, A;
    cin >> n >> k >> A; ++k;
    for(int i = 0; i < n; i++){
        int x, y, C; cin >> x >> y >> C; ++x;
        l[i] = x, r[i] = k - y; c[i] = C;
        v[r[i]].push_back(i); ct[r[i]] += c[i];
    }
    int cur_min = 0;
    for(int i = 1; i <= k; i++){
        for(auto id : v[i]){
            segTree.add(l[id] + 1, r[id], c[id], 0, 0, k);
        }
        dp[i] = min(dp[i - 1] + segTree.qry(i, i, 0, 0, k), i * A + segTree.qry(0, i - 1, 0, 0, k));
        segTree.add(i, i, dp[i] - i * A, 0, 0, k);
        for(auto id : v[i]){
            segTree.add(r[id], r[id], -c[id], 0, 0, k);
        }
    }
    cout << dp[k] << endl;
}
