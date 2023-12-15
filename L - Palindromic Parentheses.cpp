#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

string helper;
string rep(string s, int n, bool mark = false){
    string t;
    for(int i = 0; i < n; i++){
        t += s;
    }
    helper += string(t.size(), mark ? '^' : '.');
    return t;
}

const int N = 2011;
int dp[N][N];
int LPS(string s){
    int n = s.size();
    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
    }
    for(int d = 1; d < n; d++){
        for(int l = 1; l + d <= n; l++){
            int r = l + d;
            dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
            if(s[l - 1] == s[r - 1]){
                dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
            }
        }
    }
    return dp[1][n];
}

void solve(int n, int k){
    helper.clear();
    if(k < n / 2 || k >= n){
#ifndef LOCAL
        cout << -1 << '\n';
#endif
        return;
    }
    string ans;
    if(k == n / 2){
        ans = rep("(", k) + rep(")", k);
    }else if(k % 2 == 1){
        ans = 
            rep("(", (n - (k + 1)) / 2)
        +   rep("()", (k + 1) / 2, true)
        +   rep(")", (n - (k + 1)) / 2);
    }else{
        bool done = false;
        for(int k1 = 1; k1 <= n / 2; k1++){
            for(int k2 = 1; k2 <= n / 2; k2++){
                if(k1 + k2 < n / 2) continue;
                int r1 = min(k1, n / 2 - k1) * 2 + (n / 2 - k2);
                int r2 = min(k2, n / 2 - k2) * 2 + (n / 2 - k1);
                int r = max(r1, r2);
                if(r == k){
                    ans = rep("(", k1) + rep(")", n / 2 - k2) + rep("(", n / 2 - k1) + rep(")", k2);
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        if(!done){
            if(k % 2 == 1){
                ans = 
                    rep("(", (n - (k + 1)) / 2)
                +   rep("()", (k + 1) / 2)
                +   rep(")", (n - (k + 1)) / 2);
            }else{
                int r = (n - k) / 2;
                if(k % 4 == 0){
                    ans += rep("(", r);
                    ans += rep(")(", k / 4);
                    ans += rep("()", k / 4);
                    ans += rep(")", r);
                }else{
                    ans += rep("(", r + 1);
                    ans += rep(")(", k / 4);
                    ans += "))";
                    ans += rep("()", k / 4);
                    ans += rep(")", r - 1);
                }
            }
        }
    }
#ifdef LOCAL
    if(LPS(ans) != k){
        cout << n << ' ' << k << ' ' << LPS(ans) << ' ' << ans << endl;
    }
#else
    cout << ans << '\n';
#endif
    // cout << helper << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
#ifndef LOCAL
    int n, k; cin >> n >> k;
    solve(n, k);
#else
    for(int n = 2; n <= 100; n += 2){
        for(int k = 1; k <= n; k++){
            solve(n, k);
        }
    }
#endif
}
