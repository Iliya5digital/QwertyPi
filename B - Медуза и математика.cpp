#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

struct Pair{
    int x, y;
};

Pair D[100][1000];
int id[100];

int t;
int u[256][256];
int tc = 0;
void add(int x, int y){
    if(u[x][y] == tc) return;
    u[x][y] = tc;
    D[t + 1][id[t + 1]++] = {x, y};
}

vector<int> bit8;

int g(int x){
    int r = 0;
    for(int i = 0; i < 8; i++){
        if(x & bit8[i]) r += 1 << i;
    }
    return r;
}

void solve(){
    ++tc;
    int a, b, c, d, m; cin >> a >> b >> c >> d >> m;
    bit8.clear();
    for(int i = 0; i < 8; i++){
        int v = (1 << 30) - 1;
        if(i & 4) v &= a; else v &= ~a;
        if(i & 2) v &= b; else v &= ~b;
        if(i & 1) v &= m; else v &= ~m;
        bit8.push_back(v);
    }
    for(int i = 0; i < 8; i++){
        int x;
        x = c & bit8[i];
        if(x != 0 && x != bit8[i]){
            cout << -1 << '\n';
            return;
        }
        x = d & bit8[i];
        if(x != 0 && x != bit8[i]){
            cout << -1 << '\n';
            return;
        }
    }

    a = g(a), b = g(b), c = g(c), d = g(d), m = g(m);

    int ans = -1;
    int dis = 0;

    t = -1; id[0] = 0;
    add(a, b);
    while(id[dis]) {
        t = dis; id[t + 1] = 0;
        for(int j = 0; j < id[t]; j++){
            int x = D[t][j].x, y = D[t][j].y;
            if(x == c && y == d) {
                ans = dis; break;
            }
            add(x & y, y);
            add(x | y, y);
            add(x, x ^ y);
            add(x, y ^ m);
        }
        if(ans != -1) break;
        dis++;
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
