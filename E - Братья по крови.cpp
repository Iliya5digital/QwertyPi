#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 11;
vector<int> G[N];
int p[N], anc[20][N], op[N], ed[N], t;
int d[N];
vector<int> with_depth[N];
void dfs(int v, int depth = 0){
	op[v] = ++t;
	d[v] = depth;
	for(auto i : G[v]){
		dfs(i, depth + 1);
	}
	ed[v] = t;
}

int kth_anc(int v, int k){
	for(int j = 19; j >= 0; j--){
		if(k & (1 << j)) v = anc[j][v];
	}
	return v;
}

int find_int(int l, int r, int v){
	return upper_bound(with_depth[v].begin(), with_depth[v].end(), r) - lower_bound(with_depth[v].begin(), with_depth[v].end(), l);
}

int32_t main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		G[p[i]].push_back(i);
	}
	for(int i = 0; i <= n; i++){
		anc[0][i] = p[i];
	}
	for(int j = 1; j < 20; j++){
		for(int i = 0; i <= n; i++){
			anc[j][i] = anc[j - 1][anc[j - 1][i]];
		}
	}
	dfs(0);
	for(int i = 0; i <= n; i++){
		with_depth[d[i]].push_back(op[i]);
	}
	for(int i = 0; i <= n; i++){
		sort(with_depth[i].begin(), with_depth[i].end());
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int v, k; cin >> v >> k;
		int a = kth_anc(v, k - 1);
		int ans = p[a] == 0 ? 0 : find_int(op[p[a]], ed[p[a]], d[v]) - 1;
		cout << ans << ' ';
	}
	cout << endl;
}
