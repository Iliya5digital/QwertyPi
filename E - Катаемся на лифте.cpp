#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 11;
struct BIT{
    int bit[MAXN];
    void init(int n){
        for(int i = 0; i <= n; i++) bit[i] = 0;
    }
    void add(int p, int v){
        for(int i = p; i < MAXN; i += i & -i) bit[i] += v;
    }
    int qry(int p){
        int r = 0;
        for(int i = p; i; i -= i & -i) r += bit[i]; // ???
        r %= MOD;
        return r;
    }
} bit;

void solve(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> cur(n + 1), nxt(n + 1);
    cur[a] = 1;
    for(int i = 0; i < k; i++){
        bit.init(n);
        for(int j = 1; j <= n; j++){
            if(j == b) continue;
            if(j < b){
                int l = max(1LL, j * 2 - b + 1);
                bit.add(l, cur[j]); bit.add(j, -cur[j]);
                bit.add(j + 1, cur[j]); bit.add(b, -cur[j]);
            }else{
                int r = min(n, j * 2 - b - 1);
                bit.add(b + 1, cur[j]); bit.add(j, -cur[j]);
                bit.add(j + 1, cur[j]); bit.add(r + 1, -cur[j]);
            }
        }
        for(int j = 1; j <= n; j++){
            nxt[j] = bit.qry(j);
        }
        cur.swap(nxt);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += cur[i];
    }
    ans %= MOD;
    cout << ans << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
