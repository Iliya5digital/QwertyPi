#include <bits/stdc++.h>
#define int long long
using namespace std;

int g[1 << 18];
int s[1 + (1 << 18)];
int v1[1 << 18], v2[1 << 18];
vector<pair<int, int>> v[1 << 17];

int f(int x){
    int r = 0;
    for(int i = 0; i < 17; i++){
        int y = x; y >>= i * 2; y &= 3;
        assert(y == 0 || y == 3);
        if(y == 3) r |= (1 << i);
    }
    return r;
}

void solve(){
    int k; cin >> k;
    fill(v1, v1 + (1 << k + 1), -1);
    for(int i = 0; i < (1 << k); i++){
        v[i].clear(); v1[i] = -1;
    }
    for(int i = 0; i < (1 << k + 1); i++){
        cin >> g[i]; s[i + 1] = s[i] ^ g[i];
    }
    for(int i = 0; i <= (1 << k + 1); i++){
        int x = 0;
        for(int j = 0; j < k; j++){
            int y = s[i]; y >>= j * 2; y &= 3;
            if(y == 0 || y == 3) x |= (1 << j);
        }
        v[x].push_back({s[i], i});
    }
    for(int i = 0; i < (1 << k); i++){
        sort(v[i].begin(), v[i].end(), [](pair<int, int> p1, pair<int, int> p2){
            return p1.second < p2.second;
        });
        for(int j = 1; j < v[i].size(); j++){
            int x = v[i][j - 1].first ^ v[i][j].first;
            x = f(x);
            if(v1[x] == -1){
                v1[x] = v[i][j - 1].second;
                v2[x] = v[i][j].second;
            }else{
                vector<int> a{v1[x], v2[x], v[i][j - 1].second, v[i][j].second};
                sort(a.begin(), a.end());
                cout << a[0] + 1 << ' ' << a[1] << ' ' << a[2] + 1 << ' ' << a[3] << endl;
                return;
            }
        }
    }
    assert(0 == 1);
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        solve();
    }
}
