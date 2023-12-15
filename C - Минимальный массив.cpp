#include <bits/stdc++.h>
#define int long long
using namespace std;

// Oops

const int N = 5e5 + 11;
int a[N], b[N], c[N];
bool ex[N];
struct BIT{
    int bit[N];
    void add(int qi, int qv){ ++qi; for(int i = qi; i < N; i += i & -i) bit[i] += qv; }
    int bs(){ int b = 0; for(int j = 21; j >= 0; j--) if(b + (1 << j) < N && bit[b + (1 << j)] == 0) b += (1 << j); return b; }
} bit;

vector<int> U;

void solve(){
    U.clear();
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) b[i] = c[i] = 0;
    for(int i = 0; i <= n; i++) bit.bit[i] = 0;
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r, x; cin >> l >> r >> x; ++r;
        U.push_back(l); U.push_back(r);
        if(c[l] != 0) bit.add(l, -1);
        if(c[r] != 0) bit.add(r, -1);
        c[l] += x; c[r] -= x;
        if(c[l] != 0) bit.add(l, 1);
        if(c[r] != 0) bit.add(r, 1);

        int p = bit.bs();
        if(p > n) continue;
        else if(c[p] < 0){
            sort(U.begin(), U.end()); U.resize(unique(U.begin(), U.end()) - U.begin());
            for(auto i : U) ex[i] = false;
            for(auto i : U) if(!ex[i]) ex[i] = true, b[i] += c[i];
            for(auto i : U) if(c[i] != 0) bit.add(i, -1), c[i] = 0;
            U.clear();
        }
    }
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];
    for(int i = 1; i <= n; i++) cout << a[i] + b[i] << ' '; cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
