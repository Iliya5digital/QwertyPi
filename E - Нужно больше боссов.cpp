#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 11; 
vector<int> G[N];
int st[N], low[N], t;
int bcc[N];
bool vis[N];
set<int> br[N];
vector<pair<int, int>> br_e;

void add_bridge(int u, int v){
	br[u].insert(v);
	br[v].insert(u);
	br_e.push_back({u, v});
}

void dfs(int v, int pa = -1){
	st[v] = low[v] = ++t;
	for(auto i : G[v]){
		if(!st[i]){
			dfs(i, v);
			low[v] = min(low[v], low[i]);
			if(low[i] > st[v]){
				add_bridge(i, v);
			}
		}else if(i != pa){
			low[v] = min(low[v], st[i]);
		}
	}
}

void dfs2(int rt, int v){
	bcc[v] = rt; vis[v] = true;
	for(auto i : G[v]){
		if(!vis[i] && !br[v].count(i)){
			dfs2(rt, i);
		}
	}
}

int ans = 0, dp[N];
void dfs3(int v, int pa = -1){
	vector<int> sons;
	for(auto i : G[v]){
		if(i != pa){
			dfs3(i, v);
			sons.push_back(dp[i]);
		}
	}
	sort(sons.begin(), sons.end(), [](int a, int b){
		return a > b;
	});
	if(sons.size() == 1) ans = max(ans, sons[0] + 1);
	if(sons.size() >= 2) ans = max(ans, sons[0] + sons[1] + 2);
	dp[v] = sons.size() ? sons[0] + 1 : 0;
}

int32_t main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs2(i, i);
	}
	for(int i = 1; i <= n; i++) G[i].clear();
	for(auto& [u, v] : br_e){
		G[bcc[u]].push_back(bcc[v]);
		G[bcc[v]].push_back(bcc[u]);
	}
	if(br_e.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	dfs3(bcc[br_e[0].first]);
	cout << ans << endl;
}
