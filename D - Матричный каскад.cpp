#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 6e3 + 11;
bool a[N_MAX][N_MAX];

struct BIT{
    int bit[N_MAX][N_MAX] = {};
    void add(int x, int y, int v){
        x++; y++;
        for(int i = x; i < N_MAX; i += i & -i){
            for(int j = y; j < N_MAX; j += j & -j){
                bit[i][j] += v;
            }
        }
    }
    int qry(int x, int y){
        x++; y++;
        int ret = 0;
        for(int i = x; i; i -= i & -i){
            for(int j = y; j; j -= j & -j){
                ret += bit[i][j];
            }
        }
        return ret;
    }
} bit;

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j] == '1';
        }
    }
    for(int i = 0; i < n * 2 + 10; i++){
        for(int j = 0; j < n * 2 + 10; j++){
            bit.bit[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((a[i][j] + bit.qry(i + j, n + i - j)) % 2 == 1){
                ans++; bit.add(i + j, n + i - j, 1);
            }
        }
    }
    cout << ans << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
