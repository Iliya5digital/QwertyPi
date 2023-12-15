#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 11;
int a[N], b[N], c[N];
void solve(){
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    int y = 0;
    for(int i = 0; i < n; i++){
        if((a[i] | x) == x){
            y |= a[i];
        }else{
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if((b[i] | x) == x){
            y |= b[i];
        }else{
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if((c[i] | x) == x){
            y |= c[i];
        }else{
            break;
        }
    }
    cout << ((x == y) ? "YES" : "NO") << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
