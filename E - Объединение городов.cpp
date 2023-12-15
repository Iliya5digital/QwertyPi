#include <bits/stdc++.h>
 
using namespace std;
 
struct DSU{
    int dsu[3011], r1[3011], r2[3011], c1[3011], c2[3011];
    void init(int n, int m){ for(int i = 0; i < n * m; i++) { dsu[i] = i; r1[i] = r2[i] = i / m; c1[i] = c2[i] = i % m; } }
    int f(int x){ return x == dsu[x] ? x : dsu[x] = f(dsu[x]); }
    void g(int x, int y){ 
        x = f(x), y = f(y); 
        r1[x] = min(r1[x], r1[y]);
        r2[x] = max(r2[x], r2[y]);
        c1[x] = min(c1[x], c1[y]);
        c2[x] = max(c2[x], c2[y]);
        dsu[y] = x;
    }
} dsu;
 
 
char a[52][52];
 
void we_connect(int r1, int r2, int c1, int c2){
    for(int i = min(r1, r2); i <= max(r1, r2); i++) a[i][c1] = '#';
    for(int i = min(c1, c2); i <= max(c1, c2); i++) a[r2][i] = '#';
}
 
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    dsu.init(n, m);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '#' && a[i + 1][j] == '#'){
                dsu.g(i * m + j, (i + 1) * m + j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(a[i][j] == '#' && a[i][j + 1] == '#'){
                dsu.g(i * m + j, i * m + (j + 1));
            }
        }
    }
    set<int> city;
    for(int i = 0; i < n * m; i++){
        if(a[i / m][i % m] == '#') city.insert(dsu.f(i));
    }
    int A = *city.begin(), B = *++city.begin();
 
    if(dsu.r2[A] < dsu.r1[B] && dsu.c2[A] < dsu.c1[B]) we_connect(dsu.r2[A], dsu.r1[B], dsu.c2[A], dsu.c1[B]);
    if(dsu.r2[B] < dsu.r1[A] && dsu.c2[A] < dsu.c1[B]) we_connect(dsu.r1[A], dsu.r2[B], dsu.c2[A], dsu.c1[B]);
    if(dsu.r2[A] < dsu.r1[B] && dsu.c2[B] < dsu.c1[A]) we_connect(dsu.r2[A], dsu.r1[B], dsu.c1[A], dsu.c2[B]);
    if(dsu.r2[B] < dsu.r1[A] && dsu.c2[B] < dsu.c1[A]) we_connect(dsu.r1[A], dsu.r2[B], dsu.c1[A], dsu.c2[B]);
 
    while(true){
        bool upd = false;
        for(int i = 0; i < n; i++){
            int c1 = m, c2 = -1;
            for(int j = 0; j < m; j++){
                if(a[i][j] == '#') c1 = min(c1, j), c2 = max(c2, j); 
            }
            for(int j = c1; j <= c2; j++){
                if(a[i][j] == '.') a[i][j] = '#', upd = true;
            }
        }
        for(int i = 0; i < m; i++){
            int r1 = n, r2 = -1;
            for(int j = 0; j < n; j++){
                if(a[j][i] == '#') r1 = min(r1, j), r2 = max(r2, j);
            }
            for(int j = r1; j <= r2; j++){
                if(a[j][i] == '.') a[j][i] = '#', upd = true;
            }
        }
        if(!upd) break;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
}
 
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
