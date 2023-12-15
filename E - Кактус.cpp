#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
 
const int MAXN = 2e5 + 11; 
int cycleId[MAXN], csz[MAXN], dp[MAXN];
bool vis[MAXN]; 
vector<pair<int, int>> G[MAXN];
bool in_stack[MAXN];
void dfs(int v, int pa = -1){
	cycleId[v] = v; dp[v] = 0; vis[v] = true; in_stack[v] = true;
	for(auto& [i, e] : G[v]){
		if(!vis[i]){ // T
			dfs(i, v);
			if(dp[i] > 0){
				cycleId[v] = cycleId[i];
			}
			dp[v] += dp[i];
		}else if(i != pa && in_stack[i]){ // B
			cycleId[v] = e;
			dp[i]--; dp[v]++;
		}
	}
	in_stack[v] = false;
}
 
int p[MAXN], x[MAXN], dep[MAXN];
int anc[20][MAXN], anx[20][MAXN];
int n, m;
void dfs2(int v, int pa = -1){
	for(auto& [i, e] : G[v]){
		if(i != pa){
			dep[i] = dep[v] + 1;
			p[i] = v;
			anc[0][i] = p[i];
			anx[0][i] = x[i];
			for(int j = 1; j < 20; j++){
				anc[j][i] = anc[j - 1][anc[j - 1][i]];
				anx[j][i] = anx[j - 1][i] + anx[j - 1][anc[j - 1][i]];
			}
			dfs2(i, v);
		}
	}
}
 
int kth_anc(int v, int k){
	for(int i = 19; i >= 0; i--){
		if(k & (1 << i)){
			v = anc[i][v];
		}
	}
	return v;
}
 
int kth_sum(int v, int k){
	int s = 0;
	for(int i = 19; i >= 0; i--){
		if(k & (1 << i)){
			s += anx[i][v];
			v = anc[i][v];
		}
	}
	return s;
}
 
int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	u = kth_anc(u, dep[u] - dep[v]);
	for(int j = 19; j >= 0; j--){
		if(anc[j][u] != anc[j][v]){
			u = anc[j][u], v = anc[j][v];
		}
	}
	return u == v ? u : anc[0][u];
}
 
const int MOD = 1e9 + 7;
int pm(int a, int b){
	if(b == 0) return 1;
	return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}
 
int qry(int u, int v){
	int l = lca(u, v);
	int s = kth_sum(u, dep[u] - dep[l])
		+ 	kth_sum(v, dep[v] - dep[l])
		+	x[l];
	return pm(2, s);
}
 
void add_edge(int u, int v){
	// cout << "E " << u << ' ' << v << endl;
	if(u == v) return;
	G[u].push_back({v, -1});
	G[v].push_back({u, -1});
}
 
int32_t main(){
	cin.tie(0); cout.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	vector<pair<int, int>> E;
	E.push_back({-1, -1});
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		G[u].push_back({v, n + i});
		G[v].push_back({u, n + i});
		E.push_back({u, v}); 
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		G[i].clear();
	}
	for(int i = 1; i <= n; i++){
		add_edge(i, cycleId[i]);
	}
	for(int i = 1; i <= m; i++){
		if(cycleId[E[i].fi] != cycleId[E[i].se]) add_edge(cycleId[E[i].fi], cycleId[E[i].se]);
	}
	for(int i = 1; i <= n; i++) csz[cycleId[i]]++;
	for(int i = 1; i <= n + m; i++) {
		x[i] = i > n && csz[i] >= 3;
	}
	dfs2(1);
	int k; cin >> k;
	for(int i = 0; i < k; i++){
		int u, v; cin >> u >> v;
		cout << qry(u, v) << endl;
	}
}
