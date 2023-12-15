#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 11;
vector<pair<int, int>> G[N];
vector<pair<int, int>> E;
struct Edge{
	int u, v, id;
};

void add_edge(int u, int v, int eid){
	G[u].push_back({v, eid});
	G[v].push_back({u, eid});
	E.push_back({u, v});
}
bool vis[N]; int colour[N], dp[N], dp2[N], e[N];
bool invalid[N], invalid_e[N], tree[N], in_stack[N];
void dfs(int rt, int v, int pa = -1){
	vis[v] = true; in_stack[v] = true;
	if(pa == -1) colour[v] = 1;
	for(auto& [i, eid] : G[v]){
		if(!vis[i]){
			colour[i] = 3 - colour[v];
			tree[eid] = true;
			e[eid] = i;
			dfs(rt, i, v);
			dp[v] += dp[i];
			dp2[v] += dp2[i];
		}else if(in_stack[i] && i != pa){
			if(colour[i] + colour[v] != 3) {
				invalid[rt] = true, invalid_e[eid] = true;
				dp[v]++; dp[i]--;
			}
			dp2[v]++; dp2[i]--;
		}
	}
	in_stack[v] = false;
}

int32_t main(){
	int n, m; cin >> n >> m;
	E.push_back({-1, -1});
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		add_edge(u, v, i);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i, i);
	}
	int s = accumulate(invalid, invalid + n + 1, 0LL);
	vector<int> ans;
	if(s == 0){
		for(int i = 1; i <= m; i++) ans.push_back(i);
	}else if(s == 1){
		int rt; for(int i = 1; i <= n; i++) if(invalid[i]) rt = i;
		// Back Edges
		int inv_et = accumulate(invalid_e + 1, invalid_e + m + 1, 0LL);
		if(inv_et == 1){
			for(int i = 1; i <= m; i++){
				if(invalid_e[i]){
					ans.push_back(i);
				}
			}
		}
		// Span Edges
		for(int i = 1; i <= m; i++){
			if(tree[i] && dp[e[i]] == dp2[e[i]] && dp2[e[i]] == inv_et){
				ans.push_back(i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto a : ans) cout << a << ' '; cout << endl;
}
