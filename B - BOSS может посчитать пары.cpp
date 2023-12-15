#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
 
const int N = 2e5 + 11;
int a[N], b[N];
 
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x + FIXED_RANDOM;
    }
};
 
unordered_map<int, int, custom_hash> M[N];
 
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
	    M[i].clear();
	}
	for(int i = 0; i < n; i++){
		M[a[i]][b[i]]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int R = min(a[i], n * 2 / a[i]);
		for(int j = 1; j <= R; j++){
			int v = a[i] * j - b[i];
			if((j < a[i] || v <= b[i]) && v >= 1 && v <= n) {
				ans += M[j].count(v) ? M[j][v] : 0;
			}
		}
	}
	
	map<pair<int, int>, int> M2;
	for(int i = 0; i < n; i++){
		M2[{a[i], b[i]}]++;
	}
	for(auto [p, c] : M2){
		int a = p.fi, b = p.se;
		if(a * a == b + b){
			ans -= c * (c + 1) / 2;
		}
	} 
	cout << ans << endl;
}
 
int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}
