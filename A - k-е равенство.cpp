#include <bits/stdc++.h>
#define int long long
using namespace std;

int pw10[7] = {1};
void solve(){
    for (int i = 1; i <= 6; i++) pw10[i] = pw10[i - 1] * 10;
    int A, B, C, k; cin >> A >> B >> C >> k;
    if(C < max(A, B) || C > max(A, B) + 1){
        cout << -1 << endl;
        return;
    }
    
    bool la = C == max(A, B) + 1;
    for(int a = pw10[A - 1]; a < pw10[A]; a++){
        int l = pw10[B - 1], r = pw10[B] - 1; // [l, r]
        l = max(l, pw10[C - 1] - a);
        r = min(r, pw10[C] - 1 - a);
        if(l > r) continue;
        if(k <= r - l + 1){
            cout << a << " + " << l + k - 1 << " = " << a + l + k - 1 << endl;
            return;
        }
        k -= r - l + 1;
    }
    cout << -1 << endl;
    return;
}

int32_t main(){
    int T; cin >> T;
    while(T--){
        solve();
    }
}
