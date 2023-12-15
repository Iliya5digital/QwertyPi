#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x; cin >> x;
    vector<int> a;
    a.push_back(x);
    for(int j = 0; j < 30; j++){
        if(x & (1 << j)){
            if(x != (1 << j)){
                x -= (1 << j);
                a.push_back(x);
            }
        }
    }
    for(int j = 29; j >= 0; j--){
        if(x == (1 << j + 1)){
            x -= (1 << j);
            a.push_back(x);
        }
    }
    cout << a.size() << endl;
    for(auto i : a) cout << i << ' '; cout << endl;
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
