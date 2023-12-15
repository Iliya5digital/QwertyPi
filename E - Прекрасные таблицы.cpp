#include <bits/stdc++.h>

// failed IMO, only got Bronze
// At least give me some CF rating

using namespace std;

const int MAXT = 4e3;
struct DSU{
    int dsu[MAXT << 2];
    void in(int n){
        for(int i = 0; i <= n; i++) dsu[i] = i;
    }
    int f(int x){
        if(x == dsu[x]) return x;
        return dsu[x] = f(dsu[x]);
    }
    void g(int x, int y){
        x = f(x), y = f(y);
        dsu[x] = y;
    }
} D;

int n, m, k; 
int x(int t, int ty){
    return t * 2 + ty;
}
int y(int t, int ty){
    return (n + t) * 2 + ty;
}

void solve(){
    cin >> n >> m >> k;
    D.in((n + m) * 2);
    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;
        for(int d = 0; d < 2; d++){
            if(y1 < y2)
                D.g(x(x1, d), y(y1, 1 - d));
            else
                D.g(x(x1, d), y(y2, d));
        }
    }
    for(int i = 0; i < (n + m); i++){
        if(D.f(i * 2) == D.f(i * 2 + 1)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
