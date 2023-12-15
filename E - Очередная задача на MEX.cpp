#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int N = 5000 + 11;
int a[N], c[N], nxt[N];
bool dp[N][1 << 13];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + (1 << 13), 0);
    fill(nxt, nxt + n + 1, -1);
    dp[0][0] = true;
    for(int r = 0; r < n; r++){
        int mex = 0; fill(c, c + n + 1, 0);
        for(int l = r; l >= 0; l--){
            c[a[l]]++; while(c[mex]) mex++;
            if (nxt[mex] < l) {
                for(int i = 0; i < (1 << 13); i++){
                    dp[r + 1][i ^ mex] |= dp[l][i];
                }
                nxt[mex] = l;
            }
        }
        for(int i = 0; i < (1 << 13); i++){
            dp[r + 1][i] |= dp[r][i];
        }
    }
    for(int i = (1 << 13) - 1; i >= 0; i--){
        if(dp[n][i]){
            cout << i << '\n';
            return;
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
