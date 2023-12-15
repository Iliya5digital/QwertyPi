#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[51], b[51];
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    int s_a = accumulate(a, a + n, 0LL);
    int s_b = accumulate(b, b + m, 0LL);
    if(s_a > s_b){
        cout << "Tsondu" << endl;
    }else if(s_a < s_b){
        cout << "Tenzing" << endl;
    }else{
        cout << "Draw" << endl;
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
