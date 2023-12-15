#include <bits/stdc++.h>

using namespace std;

const int N = 4001;
const int INF = 1 << 30;
int dp[N][N], c[N][N], a[N][N], s[N][N];
int f(int L, int R){
	return s[R][R] - s[L - 1][R] - s[R][L - 1] + s[L - 1][L - 1];
}

void solve(int i, int L, int R, int optL, int optR){
	if(L > R) return;
	int M = (L + R) / 2;
	int opt = optL;
	for(int p = optL + 1; p <= optR; p++){
		if(dp[i - 1][p] + f(p + 1, M) < dp[i - 1][opt] + f(opt + 1, M)){
			opt = p;
		}
	}
	dp[i][M] = dp[i - 1][opt] + f(opt + 1, M);
	solve(i, L, M - 1, optL, opt);
	solve(i, M + 1, R, opt, optR);
}

int32_t main(){
	cin.tie(0); cout.tie(0)->sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j];
		}
	}
	fill(dp[0] + 1, dp[0] + 1 + n, INF);
	for(int i = 1; i <= k; i++){
		solve(i, 1, n, 0, n - 1);
	}
	cout << dp[k][n] / 2 << endl;
}
