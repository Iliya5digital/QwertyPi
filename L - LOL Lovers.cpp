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
    int n; cin >> n; string s; cin >> s;
    for(int a = 1; a <= n - 1; a++){
        string t1 = s.substr(0, a);
        string t2 = s.substr(a);
        if(count(all(t1), 'L') != count(all(t2), 'L')
        && count(all(t1), 'O') != count(all(t2), 'O')){
            cout << a << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
