#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 11;
int a[N];

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    set<int> S;
    for (int i = 0; i < n; i++) {
        if(a[i] == 1) S.insert(i);
    }
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int s; cin >> s;
            int sum = n * 2 - S.size();
            if(s > sum){
                cout << "NO" << '\n';
                continue;
            }
            if (S.empty()) {
                cout << (s % 2 == 0 ? "YES" : "NO") << '\n';
                continue;
            }
            int L = *S.begin(), R = *--S.end();
            if(sum % 2 == s % 2){
                cout << "YES" << '\n';
                continue;
            }
            if(s <= sum - 1 - min(L * 2, (n - R - 1) * 2)){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }else{
            int i, v; cin >> i >> v; --i;
            if (v == 2) {
                S.erase(i);
            } else {
                S.insert(i);
            }
        }
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
