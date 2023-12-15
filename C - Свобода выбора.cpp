#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

typedef long long ll;

using namespace std;

const int M = 1e5 + 11;

struct Pair{
    int a, c;
};

vector<Pair> x[M];
int n[M], l[M], r[M], t[M];
vector<pair<int, int>> V[M];

void solve(){
    int m; cin >> m; int N = 0, T = 0, L = 0, R = 0;
    for(int i = 0; i < m; i++){
        cin >> n[i] >> l[i] >> r[i];
        N += n[i]; L += l[i]; R += r[i];
        x[i].resize(n[i]); 
        for(int j = 0; j < n[i]; j++){
            cin >> x[i][j].a;
        }
        t[i] = 0;
        for(int j = 0; j < n[i]; j++){
            cin >> x[i][j].c; t[i] += x[i][j].c;
        }
    }
    if(R - L >= N){
        cout << 0 << '\n';
        return;
    }
    for(int i = 0; i < N; i++) V[i].clear();
    for(int i = 0; i < m; i++){
        auto& y = x[i];
        for(int j = 0; j < n[i]; j++){
            if(y[j].a >= L && y[j].a < L + N){
                V[y[j].a - L].push_back({i, y[j].c});
            }
        }
    }

    int ans = 1LL << 60;
    for(int i = 0; i <= R - L; i++){
        int cnt = L + i;
        int curR = R, res = 0;
        for(auto [b, c] : V[i]){
            curR -= r[b];
            int non = t[b] - c;
            curR += max(l[b], non);
            if(l[b] > non) res += l[b] - non;
        }
        res += max(0LL, cnt - curR);
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        #ifdef LOCAL
            cerr << "Case #" << t << ": " << '\n';
        #endif
        solve();
    }
}
