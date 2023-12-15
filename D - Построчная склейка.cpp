#include <bits/stdc++.h>

// failed IMO, only got Bronze
// At least give me some CF rating

// More difficult than IMO Q5

using namespace std;

int cnt[27];
string s;

int get(int idx){
    return (idx < 0 || idx >= s.size()) || s[idx] == 0 ? 0 : s[idx] - 'a' + 1;
}

void solve(){
    int n; cin >> n;
    s.resize(n); fill(s.begin(), s.end(), 0);
    int k = 0, x = n;
    for(int T = 2; T <= 26; T++){
        if(n % T != 0){
            for(int i = 0; i < n; i++){
                cout << (char) ('a' + (i % T));
            }
            cout << endl;
            return;
        }
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}
