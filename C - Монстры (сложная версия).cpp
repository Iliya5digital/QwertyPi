#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 11;
int a[N];
int mx[N << 2], t[N << 2], c[N << 2], p[N << 2];
int n;

void init(int v = 0, int l = 1, int r = n){
    if(l == r) t[v] = l, p[v] = 0;
    else {
        int m = (l + r) / 2;
        init(v * 2 + 1, l, m);
        init(v * 2 + 2, m + 1, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]); p[v] = 0;
    }
}

void push(int v){
    if(p[v] != 0){
        t[v * 2 + 1] += p[v];
        t[v * 2 + 2] += p[v];
        p[v * 2 + 1] += p[v];
        p[v * 2 + 2] += p[v];
        p[v] = 0;
    }
}
void sadd(int ql, int qr, int qi, int v = 0, int tl = 1, int tr = n){
    if(qr < tl || tr < ql) return;
    if(ql <= tl && tr <= qr) t[v] += qi, p[v] += qi;
    else {
        push(v);
        int m = (tl + tr) / 2;
        sadd(ql, qr, qi, v * 2 + 1, tl, m);
        sadd(ql, qr, qi, v * 2 + 2, m + 1, tr);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}
int qry(int v = 0, int l = 1, int r = n){
    if(l == r) { return t[v] < 0 ? l : 0; }
    push(v);
    int m = (l + r) / 2;
    if(t[v * 2 + 1] < 0) return qry(v * 2 + 1, l, m);
    else return qry(v * 2 + 2, m + 1, r);
}

struct BIT{
    int bit[N];
    void clear(){
        for(int i = 0; i <= n; i++) bit[i] = 0;
    }
    void add(int p, int v){
        for(int i = p; i < N; i += i & -i) bit[i] += v;
    }
    int qry(int p){
        int r = 0;
        for(int i = p; i; i -= i & -i) r += bit[i];
        return r;
    }
    int bs(){
        int r = 0;
        for(int j = 19; j >= 0; j--) if(r + (1 << j) <= n && bit[r + (1 << j)] == 0) r += (1 << j);
        return r + 1;
    }
} bit, bit2;

void add(int v, int dv){
    bit.add(v, dv), bit2.add(v, dv * v);
    sadd(v, n, -dv);
}

int ans[N];
void solve(){
    cin >> n; bit.clear(), bit2.clear();
    for(int i = 1; i <= n; i++) cin >> a[i]; init();
    int m = 0, s = 0;
    for(int i = 1; i <= n; i++){
        if(bit.qry(a[i]) < a[i]) add(a[i], 1);
        int f = qry(); if(f != 0) add(f, -1);
        int k = bit.qry(n); 
        ans[i] = bit2.qry(n) - k * (k + 1) / 2;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
