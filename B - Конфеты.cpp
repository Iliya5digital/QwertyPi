#include <bits/stdc++.h>

using namespace std;

int a[101];
void solve(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << -1 << endl;
    }else{
        vector<int> v;
        while(n != 1){
            if(n % 4 == 3){
                v.push_back(2);
                n = n / 4 * 2 + 1;
            }else{
                v.push_back(1);
                n = n / 4 * 2 + 1;
            }
        }
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for(auto i : v) cout << i << ' '; cout << endl;
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--) solve();
}
