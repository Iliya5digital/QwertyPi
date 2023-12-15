#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[5001];
// ?????
void solve(){
    int n, b, k1, k2;
    cin >> n >> b >> k1 >> k2;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, [](int x, int y) { return x > y; });
    int ans = 1LL << 60;
    for(int i = 0; i <= min(k1, k2); i++){
        int c = 0;
        for(int j = 0; j < i; j++){
            c += max(((a[j] + 1) / 2) - b, 0LL);
        }
        k1 -= i, k2 -= i;
        for(int j = min(i + k1 + k2, n); j < n; j++){
            c += a[j];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int j = i; j < min(i + k1 + k2, n); j++){
            c += (a[j] + 1) / 2;
            pq.push(max(a[j] - b, 0LL) - (a[j] + 1) / 2);
        }
        for(int j = 0; j < k2; j++){
            c += pq.top(); pq.pop();
        }
        k1 += i, k2 += i;
        ans = min(ans, c);
    }
    cout << ans << endl;
}
 
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
