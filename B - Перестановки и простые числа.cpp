#include <bits/stdc++.h>

// failed IMO, only got Bronze
// At least give me some CF rating

using namespace std;

const int MAXN = 2e5 + 11;
int a[MAXN];
void solve(){
    int n; cin >> n;
    if(n <= 2){
        for(int i = 1; i <= n; i++){
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    fill(a, a + n, 0);
    a[n / 2] = 1;
    a[0] = 2;
    a[n - 1] = 3;
    int c = 4;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) a[i] = c++;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int32_t main(){
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}
