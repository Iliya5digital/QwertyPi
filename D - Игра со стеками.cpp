#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 11;
vector<int> c[N];
int c2[N];
int cnt[N], ans[N];
int p[N]; bool in_p[N]; int pid = 0;
void rem(int i){
    c2[i] = c[i].back(); c[i].pop_back();
    cnt[c2[i]]++; cnt[i]--;
    if(cnt[c2[i]] > 0 && !in_p[c2[i]]) p[pid++] = c2[i], in_p[c2[i]] = true;
}

int dfs(int v){
    if(ans[v]) return ans[v];
    if(c2[v] == 0) return ans[v] = v;
    return ans[v] = dfs(c2[v]);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int r; cin >> r;
        for(int j = 0; j < r; j++){
            int x; cin >> x; c[i].push_back(x);
        }
        reverse(c[i].begin(), c[i].end());
    }
    for(int i = 1; i <= n; i++){
        for(auto j : c[i]) cnt[j]--;
        cnt[i] += c[i].size();
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] > 0) p[pid++] = i, in_p[i] = true;
    }
    while(pid > 0){
        int x = p[--pid];
        while(cnt[x] > 0) rem(x);
        in_p[x] = false;
    }
    for(int i = 1; i <= n; i++){
        if(!ans[i]) ans[i] = dfs(i);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
