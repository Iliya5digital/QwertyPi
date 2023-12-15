#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200011];
int l[200011], r[200011];
int dl[200011], dr[200011];
int32_t main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int s = accumulate(a, a + n, 0LL);
    l[0] = 0, dl[0] = 0; for(int i = 0; i < n; i++) l[i + 1] = l[i] + (-a[i] * 2), dl[i + 1] = max(dl[i], l[i]);
    r[n] = 0, dr[n] = 0; for(int i = n - 1; i >= 0; i--) r[i] = r[i + 1] + (-a[i] * 2), dr[i] = max(r[i], dr[i + 1]);
    int ans = -(1LL << 60);
    for(int i = 0; i <= n; i++){
        ans = max(ans, dl[i] + dr[i] + s);
    }
    cout << ans << endl;
}
