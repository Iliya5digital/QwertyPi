#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 11;
const int INF = 1LL << 60;
int d[N], h[N], t[N], s[N];
int dp[2][N];

int f(int L, int R){
	return t[R] * (R - L + 1) - (s[R] - s[L - 1]);
}

void solve(int L, int R, int optL, int optR){
	if(L > R) return;
	int M = (L + R) / 2;
	int opt = optL;
	for(int p = optL + 1; p <= optR; p++){
		if(dp[0][p] + f(p + 1, M) < dp[0][opt] + f(opt + 1, M))
			opt = p;
	}
	dp[1][M] = dp[0][opt] + f(opt + 1, M);
	solve(L, M - 1, optL, opt);
	solve(M + 1, R, opt, optR);
}

int32_t main(){
	int n, m, p; cin >> n >> m >> p;
	for(int i = 2; i <= n; i++) cin >> d[i];
	for(int i = 2; i <= n; i++) d[i] += d[i - 1];
	for(int i = 1; i <= m; i++){
		cin >> h[i] >> t[i]; t[i] -= d[h[i]];
	}
	for(int i = 1; i <= m; i++) s[i] = s[i - 1] + t[i];
	sort(t + 1, t + m + 1);
	fill(dp[0] + 1, dp[0] + m + 1, INF);
	for(int i = 0; i < p; i++){
		solve(1, m, 0, m - 1);
		for(int j = 0; j <= m; j++)
			dp[0][j] = dp[1][j];
	}
	cout << dp[1][m] << endl;
}
