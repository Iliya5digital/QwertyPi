#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 11;
int dp[N][N], dp2[N], dp3[N], sz[N];

vector<int> G[N], sg[N];

int d[N];
void dfs(int v, int par = -1, int dep = 1){
    sz[v] = 1; d[dep]++;
    for(auto u : G[v]){
        if(u != par){
            dfs(u, v, dep + 1);
        }
    }
}

int ans[N];
int32_t main(){
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(ans, ans + n + 1, 1LL << 60);
    for(int i = 1; i <= n; i++){
        fill(d + 1, d + n + 1, 0); dfs(i);
        int x = 0, s = 0; ans[x] = 0;
        for(int j = 1; j <= n; j++){
            while(d[j] > 0){
                ++x; s += j; ans[x] = min(ans[x], s); --d[j];
            }
        }
    }
    for(int i = 0; i <= n; i++){
        cout << i * (n + 1) - 2 * ans[i] << ' ';
    }
    cout << endl;
}
