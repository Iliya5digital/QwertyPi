#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[1001];
void solve(){
	int n, m, c0, d0; cin >> n >> m >> c0 >> d0;
	for(int i = 0; i * c0 <= n; i++) dp[i * c0] = i * d0;
	for(int i = 0; i < n; i++) dp[i + 1] = max(dp[i], dp[i + 1]);
	for(int i = 0; i < m; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int mx = a / b;
		for(int i = n; i >= 0; i--){
			for(int j = 1; j <= mx; j++){
				if(i + j * c <= n){
					dp[i + j * c] = max(dp[i + j * c], dp[i] + j * d);
				}
			}
		}
		for(int i = 0; i < n; i++) dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	cout << dp[n] << endl;
}

int32_t main(){
	int t; t = 1;
	while(t--){
		solve(); 
	}
}
