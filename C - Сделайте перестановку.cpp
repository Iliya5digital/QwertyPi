#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100001];
void solve(){
    int n, c, d; cin >> n >> c >> d;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = n * c + d;
    int u = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 || a[i] != a[i - 1]) u++;
        ans = min(ans, (n - u) * c + (a[i] - u) * d);
    }
    cout << ans << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
