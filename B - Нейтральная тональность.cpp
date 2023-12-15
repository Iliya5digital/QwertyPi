#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

typedef long long ll;

using namespace std;

const int N = 2e5 + 11;

int a[N], b[N];
bool u[N];
int dp[N];

multiset<int> s;
vector<int> ans;
void change(int x, int y){
    while(true){
        auto ptr = s.upper_bound(x); if(ptr == s.begin()) break;
        --ptr; if(*ptr < y) break;
        ans.push_back(*ptr); s.erase(ptr);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    for(int j = 0; j < m; j++) s.insert(b[j]);
    fill(dp, dp + n + 1, 0); int c = 0;
    fill(u, u + n + 1, 0);
    ans.clear();
    for(int i = 0; i < n; i++){
        int idx = upper_bound(dp, dp + c, a[i]) - dp;
        change(dp[idx], a[i]); ans.push_back(a[i]);
        dp[idx] = a[i]; if(idx == c) ++c;
    }
    change(dp[c - 1], 0);
    while(!s.empty()){
        cout << *--s.end() << ' '; s.erase(--s.end());
    }
    for(auto i : ans) cout << i << ' ';
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        #ifdef LOCAL
            cerr << "Case #" << t << ": " << '\n';
        #endif
        solve();
    }
}
