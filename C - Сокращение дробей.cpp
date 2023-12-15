#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXV = 1e7 + 11;
int lp[MAXV];
map<int, vector<int>> ca, cb;
void solve(){
	for(int i = 2; i < MAXV; i++){
		if(!lp[i]){
			lp[i] = i;
			for(int j = i; j * i < MAXV; j++){
				if(!lp[j * i]) lp[j * i] = i;
			}
		}
	}
	
	int n, m; cin >> n >> m;
	vector<int> a; for(int i = 0; i < n; i++) {
		int v; cin >> v; a.push_back(v);
	}
	vector<int> b; for(int i = 0; i < m; i++) {
		int v; cin >> v; b.push_back(v);
	}
	
	for(int i = 0; i < n; i++){
		int v = a[i];
		while(v != 1){
			ca[lp[v]].push_back(i);
			v /= lp[v];
		}
	}
	
	for(int i = 0; i < m; i++){
		int v = b[i];
		while(v != 1){
			cb[lp[v]].push_back(i);
			v /= lp[v];
		}
	}
	
	for(int i = 1; i < MAXV; i++){
		if(lp[i] == i){
			while(ca[i].size() && cb[i].size()){
				int l = ca[i].back(), r = cb[i].back();
				ca[i].pop_back(); cb[i].pop_back();
				a[l] /= i, b[r] /= i;
			}
		}
	}
	
	cout << n << ' ' << m << endl;
	for(auto i : a) cout << i << ' '; cout << endl;
	for(auto i : b) cout << i << ' '; cout << endl;
}

int32_t main(){
	int t; t = 1;
	while(t--){
		solve(); 
	}
}
