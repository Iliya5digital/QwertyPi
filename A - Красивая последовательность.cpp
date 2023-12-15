#include <bits/stdc++.h>

using namespace std;

int a[101];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(a[i] <= i + 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
