#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>

typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

bool adj(int i, int j){
    return i != j && abs(i / 3 - j / 3) <= 1 && abs(i % 3 - j % 3) <= 1;
}

void solve(){
    char c[9];
    for(int i = 0; i < 3; i++){
        string s; cin >> s;
        for(int j = 0; j < 3; j++){
            c[i * 3 + j] = s[j];
        }
    }
    string ans = "zzz";
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                if(i != k && adj(i, j) && adj(j, k)){
                    string t;
                    t.push_back(c[i]);
                    t.push_back(c[j]);
                    t.push_back(c[k]);
                    ans = min(ans, t);
                }
            }
        }
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
