#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 11;
int a[N];
int dpL[N][2], dpR[N][2];
int32_t main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dpL[0][0] = dpL[0][1] = 0;
    for(int i = 0; i < n; i++){
        dpL[i + 1][0] = max(dpL[i][0] + 1, a[i]);
        dpL[i + 1][1] = dpL[i][1] + dpL[i + 1][0];
    }

    for(int i = n - 1; i >= 0; i--){
        dpR[i][0] = max(dpR[i + 1][0] + 1, a[i]);
        dpR[i][1] = dpR[i + 1][1] + dpR[i][0];
    }

    int ans = 1LL << 60;
    for(int i = 0; i <= n; i++){
        ans = min(ans, dpL[i][1] + dpR[i][1] + (dpL[i][0] == dpR[i][0]));
    }
    for(int i = 0; i < n; i++) ans -= a[i];
    cout << ans << '\n';
}
