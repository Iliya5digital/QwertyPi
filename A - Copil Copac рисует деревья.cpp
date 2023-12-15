#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 11;
vector<pii> G[N];
int ans = 0;
void dfs(int v, int pa = -1, int c0 = 1, int c1 = -1){
	ans = max(ans, c0);
	for(auto [u, eid] : G[v]){
		if(u == pa) continue;
		int n0, n1; 
		if(eid > c1){
			n0 = c0, n1 = eid;
		}else{
			n0 = c0 + 1, n1 = eid; 
		}
		dfs(u, v, n0, n1);
	}
}

void solve(){
	ans = 0;
	int n; cin >> n;
	vector<pii> E;
	for(int i = 1; i <= n; i++)
		G[i].clear();
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		E.push_back({u, v});
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(1);
	cout << ans << endl;
}

int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}
