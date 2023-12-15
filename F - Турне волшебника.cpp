#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 11;
set<int> G[N], H[N]; 
vector<int> tp; int ord[N];
int deg[N], p[N], vis[N]; bool in_stack[N];

void dfs_tp(int v, int pa = -1){
	vis[v] = true; in_stack[v] = true;
	for(auto i : G[v]){
		if(!vis[i]){
			p[i] = v;
			H[v].insert(i);
			dfs_tp(i, v);
		}else if(i != pa && in_stack[i]){
			H[i].insert(v);
		}
	}
	tp.push_back(v);
	ord[v] = tp.size();
	in_stack[v] = false;
}

vector<tuple<int, int, int>> ans;
void solve(){
	for(int i = 0; i < tp.size(); i++){
		int v = tp[i];
		while(H[v].size() >= 2){
			vector<int> u;
			for(int i = 0; i < 2; i++){
				u.push_back(*H[v].begin()); H[v].erase(H[v].begin());
			}
			ans.push_back({u[0], v, u[1]});
		}
		if(H[v].size() == 1 && p[v] != 0){
			vector<int> u;
			for(int i = 0; i < 1; i++){
				u.push_back(*H[v].begin()); H[v].erase(H[v].begin());
			}
			H[p[v]].erase(v);
			ans.push_back({u[0], v, p[v]});
		}
	}
}

void add_edge(int u, int v){
	G[u].insert(v);
	G[v].insert(u);
}

int32_t main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		add_edge(u, v);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			tp.clear();
			dfs_tp(i);
			solve();
		}
	}
	cout << ans.size() << endl;
	for(auto a : ans){
		cout << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << endl;
	}
}
