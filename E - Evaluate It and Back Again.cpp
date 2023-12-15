#include <bits/stdc++.h>

#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define forn(i, n) for(int i = 0; i < (n); i++)

typedef long double LD;
typedef long long ll;

const int INF = 1LL << 60;
const LD eps = 1e-9;

using namespace std;

string construct_int(int X, bool gap = false){
    string s = "0"; char op = '+';
    if(X < 0) op = '-'; X = abs(X);
    while(X != 0){
        __int128_t pw9 = 1, d = 0;
        while((__int128_t) pw9 * 9 <= X) pw9 *= 9, ++d;
        s += op; s += "1";
        for(int i = 0; i < d; i++) s += "*9";
        s += "*"; s.push_back('0' + (X / pw9));
        X %= pw9;
        if(gap) s += "-0";
    }
    if(!gap) s += op;
    return s;
}

string construct(int A, int B){
    if((A + B) % 2 != 0){
        return "12+" + construct(A - 12, B - 21);
    }

    assert((A + B) % 2 == 0);
    if(A + B != 0){
        return construct_int((A + B) / 2) + construct(A - (A + B) / 2, B - (A + B) / 2);
    }

    assert(A + B == 0);
    if(A == 0 && B == 0) return "0";

    if(A < 0){
        string R = construct(B, A);
        reverse(R.begin(), R.end());
        return R;
    }

    assert(A > 0 && B < 0 && A + B == 0);
    return construct_int(A, true);
}

void solve(){
    int a, b; cin >> a >> b;
    string ans = construct(a, b);
    cout << ans << '\n';
#ifdef LOCAL
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
#endif
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
