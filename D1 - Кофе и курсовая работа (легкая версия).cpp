#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 11;

int n, m;
int a[MAXN];

bool test(int d){
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(i / d);
    }
    reverse(v.begin(), v.end());
    int total = 0;
    for(int i = 0; i < n; i++){
        total += max(0LL, a[i] - v[i]);
    }
    return total >= m;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s = 0; for(int i = 0; i < n; i++) s += a[i];
    if(s < m){
        cout << -1 << endl;
        return;
    }
    int l = 1, r = n;
    while(l != r){
        int mid = (l + r) / 2;
        if(test(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
