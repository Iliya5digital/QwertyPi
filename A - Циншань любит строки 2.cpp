#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 11;

int ok(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] == s[n - 1 - i]) return i;
    }
    return -1;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int c0 = 0, c1 = 0;
    for(auto c : s) if(c == '0') c0++; else c1++;
    if (c0 != c1){
        cout << -1 << '\n';
        return;
    }
    string t = s;
    vector<int> ans;
    int p = ok(t);
    while(p != -1){
        int x;
        if(t[p] == '0'){
            x = t.size() - p;
        }else{
            x = p;
        }
        t.insert(x, "01");
        p = ok(t);
        ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << ' '; cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
