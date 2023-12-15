#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N_MAX = 2e5 + 11;
int a[N_MAX];
int cnt[40], cnt2[2][40];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int s = accumulate(a, a + n, 0LL);
    if(s % n != 0){
        cout << "No" << endl;
        return;
    }
    int m = s / n;
    fill(cnt, cnt + 40, 0);
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < n; i++) {
        int d = a[i] - m;
        if (d == 0) continue;
        bool ok = false;
        for (int x = 0; x <= 30; x++) {
            int r = d + (1LL << x);
            if (r > 0 && __builtin_popcount(r) == 1) {
                ok = true;
                int y = -1; while(r > 0) y++, r >>= 1;
                cnt[x]++; cnt[y]--;
            }
        }
        if (d > 0 && __builtin_popcount(d) == 1) {
            int r = d, y = -1; while(r > 0) y++, r >>= 1;
            cnt2[0][y]++;
        }
        if (d < 0 && __builtin_popcount(-d) == 1) {
            int r = -d, y = -1; while(r > 0) y++, r >>= 1;
            cnt2[1][y]++;
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }
    }
    for(int i = 39; i >= 0; i--){
        while(i > 0 && cnt[i] < 0 && cnt2[0][i - 1] > 0) cnt[i]++, cnt[i - 1] -= 2, cnt2[0][i - 1]--;
        while(i > 0 && cnt[i] > 0 && cnt2[1][i - 1] > 0) cnt[i]--, cnt[i - 1] += 2, cnt2[1][i - 1]--;
        if(cnt[i] != 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
