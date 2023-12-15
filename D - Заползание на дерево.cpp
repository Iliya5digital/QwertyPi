#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int q; cin >> q;
    vector<int> res;
    int L = 1, R = (1LL << 60);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int a, b, n; cin >> a >> b >> n;
            int newL, newR;
            if(n != 1) newL = a + 1 + (n - 2) * (a - b), newR = a + (n - 1) * (a - b);
            else newL = 1, newR = a;
            if(R < newL || newR < L) res.push_back(0);
            else {
                L = max(L, newL), R = min(R, newR);
                res.push_back(1);
            }
        }else{
            int a, b; cin >> a >> b;
            int _min = 1 + (max(L - a, 0LL) + (a - b) - 1) / (a - b),
                _max = 1 + (max(R - a, 0LL) + (a - b) - 1) / (a - b);
            if(_min != _max){
                res.push_back(-1);
            }else{
                res.push_back(_min);
            }
        }
    }
    for(auto i : res) cout << i << ' '; cout << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
