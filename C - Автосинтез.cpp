#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 11;
int a[N], c[N];
vector<int> r[N];
int type[N];
bool det[N];
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], r[i].clear();
    for(int i = 1; i <= n; i++) r[a[i]].push_back(i);
    for(int i = 1; i <= n; i++) c[i] = r[i].size();
    fill(type, type + n + 1, 2);
    vector<int> need;
    for(int i = 1; i <= n; i++){
        if(r[i].size() == 0) need.push_back(i);
    }
    while(need.size()){
        int v = need.back(); need.pop_back();
        type[v] = 1;
        assert(type[a[v]] != 1);
        if(type[a[v]] == 2){
            type[a[v]] = 0;
            c[a[a[v]]]--;
            if(c[a[a[v]]] == 0){
                need.push_back(a[a[v]]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(type[i] == 2){
            vector<int> cyc;
            int x = a[i]; while(x != i) cyc.push_back(x), x = a[x];
            cyc.push_back(i);
            if(cyc.size() % 2 == 1){
                cout << -1 << '\n';
                return;
            }
            for(int i = 0; i < cyc.size(); i += 2) type[cyc[i]] = 0, type[cyc[i + 1]] = 1;
        }
    }
    int cnt = 0; for(int i = 1; i <= n; i++) if(type[i]) cnt++;
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++) if(type[i]) cout << a[i] << ' '; cout << '\n';
}

int32_t main(){
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    while(t--){
        solve();
    }
}
