#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 11;
vector<pair<int, int>> G[N];
int st[N], low[N], f[N * 3], t = 0;
bool bridge_exist = false;
void dfs(int v, int pa = -1){
	st[v] = low[v] = ++t;
	for(auto& [i, e] : G[v]){
		if(i == pa) continue;
		if(!st[i]){
			dfs(i, v);
			if(low[i] >= st[i]){
				bridge_exist = true;
			}
			f[e < 0 ? -e : e] = 0 ^ (e > 0);
			low[v] = min(low[v], low[i]);
		}else{
			f[e < 0 ? -e : e] = 1 ^ (e > 0);
			low[v] = min(low[v], st[i]);
		}
	}
}
int32_t main(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>> E;
	E.push_back({0, 0});
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, -i});
		E.push_back({u, v});
	}
	dfs(1);
	if(bridge_exist){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= m; i++){
		if(f[i]){
			cout << E[i].first << ' ' << E[i].second << endl;
		}else{
			cout << E[i].second << ' ' << E[i].first << endl;
		}
	}
}
