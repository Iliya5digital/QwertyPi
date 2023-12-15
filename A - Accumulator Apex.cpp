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

const int N = 1e5 + 11;

struct mission{
    int require, reward, id;
    bool operator< (const mission& o) const {
        return require > o.require;
    }
};

deque<mission> dq[N];

void solve(){
    int x, k; cin >> x >> k;
    for(int i = 0; i < k; i++){
        int l; cin >> l;
        int amin = 0, sum = 0;
        dq[i].push_back({0, 0, i});
        for(int j = 0; j < l; j++){
            int r; cin >> r;
            sum += r; amin = min(amin, sum);
            if(sum > 0){
                dq[i].push_back({-amin, sum, i});
                amin = sum = 0;
            }
        }
    }

    priority_queue<mission> to_consider;
    for(int i = 0; i < k; i++){
        to_consider.push(dq[i].front());
        dq[i].pop_front();
    }

    while(!to_consider.empty()){
        mission m = to_consider.top(); to_consider.pop();
        if(m.require > x) break; x += m.reward;
        if(dq[m.id].empty()) continue;
        to_consider.push(dq[m.id].front());
        dq[m.id].pop_front();
    }

    cout << x << '\n';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
