#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1e5 + 11;
int lp[N_MAX];

int closet[N_MAX];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        int ans = 0;
        for(int j = 1; j * j <= x; j++){
            if(j * j == x){
                if(i - closet[j] > y) ans++;
            }else if(x % j == 0){
                if(i - closet[j] > y) ans++;
                if(i - closet[x / j] > y) ans++;
            }
        }
        for(int j = 1; j * j <= x; j++){
            if(x % j == 0){
                closet[j] = closet[x / j] = i;
            }
        }
        cout << ans << endl;
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1; // cin >> t;
    while(t--) {
        solve();
    }
}
