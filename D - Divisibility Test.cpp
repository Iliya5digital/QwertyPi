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

void solve(){
    int b, n; cin >> b >> n;
    int x = 1;
    for(int k = 1; k <= n; k++){
        x = x * b % n;
        if(x == 0){
            cout << 1 << ' ' << k << '\n';
            return;
        }else if(x == 1){
            cout << 2 << ' ' << k << '\n';
            return;
        }else if(x == n - 1){
            cout << 3 << ' ' << k << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
