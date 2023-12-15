#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 151;
const int INF = 1LL << 60;
int dp[2][N][N * N]; // in the first x soldiers, chosen y soldiers and with sw swaps
int q[N];

int n, k, s;
int chmin(int& x, int y) {
	x = min(x, y); return x;
}

void calc(int x, int q){
	for(int y = 0; y <= min(x, k); y++){
		for(int sw = 0; sw <= n * (n - 1); sw++){
			if(y < k) {
				chmin(dp[1][y + 1][sw + abs(y - x)], dp[0][y][sw] + q);
			}
			if(x - y < n - k) chmin(dp[1][y][sw + abs((k + x - y) - x)], dp[0][y][sw]);
		}
	}
}

int32_t main(){
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++) cin >> q[i];
	for(int y = 0; y <= n; y++){
		for(int sw = 0; sw <= n * (n - 1); sw++){
			dp[0][y][sw] = dp[1][y][sw] = INF;
		}
	}
	dp[0][0][0] = 0; 
	for(int x = 0; x < n; x++){
		calc(x, q[x]);
		for(int y = 0; y <= k; y++){
			for(int sw = 0; sw <= n * (n - 1); sw++){
				dp[0][y][sw] = dp[1][y][sw]; dp[1][y][sw] = INF;
			}
		}
	}
	
	int ans = INF;
	for(int sw = 0; sw <= min(s * 2, n * (n - 1)); sw++){
		chmin(ans, dp[0][k][sw]);
	}
	cout << ans << endl;
}
