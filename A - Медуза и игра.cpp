#include <bits/stdc++.h>

using namespace std;

int a[51], b[51];
void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    k = k < 10 ? k : 10 + k % 2;
    for(int tr = 0; tr < k; tr++){
        int mn = 0; for(int i = 1; i < n; i++) if(a[i] < a[mn]) mn = i;
        int mx = 0; for(int i = 1; i < m; i++) if(b[i] > b[mx]) mx = i;
        if(a[mn] < b[mx]) swap(a[mn], b[mx]);
        swap(a, b); swap(n, m);
    }
    if(k % 2){
        cout << accumulate(b, b + m, 0LL) << '\n';
    }else{
        cout << accumulate(a, a + n, 0LL) << '\n';
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
