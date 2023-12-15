#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 11;
const int INF = 1LL << 61;
int a[N];

int n, m, k;
int get(int idx){
    if(idx < 0) return -INF;
    if(idx >= n) return INF;
    return a[idx];
}

int floor_div(int a, int b){
    if(a < 0) return a / b - (a % b != 0);
    return a / b;
}

int test(int x){
    if(upper_bound(a, a + n, x) - lower_bound(a, a + n, x) >= k){
        return 0;
    }
    int L = 0, R = m;
    {
        int idx = lower_bound(a, a + n, x) - a;
        R = min(R, x + floor_div(get(idx + k - 1) - x - 1, 2));
    }
    {
        int idx = upper_bound(a, a + n, x) - a - 1;
        L = max(L, x - floor_div(x - get(idx - k + 1) - 1, 2));
    }
    return max(0LL, R - L + 1);
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    vector<int> v = {0, 1};
    for(int i = 0; i < n; i++){
        if(a[i] > 0) v.push_back(a[i] - 1);
        if(a[i] > 1) v.push_back(a[i] - 2);
        if(a[i] < m) v.push_back(a[i] + 1);
        if(a[i] < m - 1) v.push_back(a[i] + 2);
        v.push_back(a[i]);
    }

    int a1 = -1, a2 = -1;
    for(auto& i : v){
        int t = test(i);
        if(t > a1 || t == a1 && i < a2){
            a1 = t; a2 = i;
        }
    }
    cout << a1 << ' ' << a2 << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int T = 1; // cin >> T;
    while(T--){
        solve();
    }
}
