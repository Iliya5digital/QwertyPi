#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("unroll-loops")
using namespace std;

const int MOD = 998244353;

int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}

int mi(int a){
    return pm(a, MOD - 2);
}

int f[201], fi[201];

int c[201], t[201];
int in[201], s_in[201], out[201], s_out[201];
int dp[201][201];

int _C[201][201], _P[201][201];
int C(int n, int r){
    return _C[n][r];
}
int P(int n, int r){
    return _P[n][r];
}

int32_t main(){
    f[0] = 1; for(int i = 1; i <= 200; i++) f[i] = f[i - 1] * i % MOD;
    for(int i = 0; i <= 200; i++) fi[i] = mi(f[i]);
    for(int i = 0; i <= 200; i++) for(int j = 0; j <= i; j++) _C[i][j] = f[i] * fi[i - j] % MOD * fi[j] % MOD;
    for(int i = 0; i <= 200; i++) for(int j = 0; j <= i; j++) _P[i][j] = f[i] * fi[i - j] % MOD;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 1; i <= n; i++) in[t[i]] += c[i], out[t[i]]++;
    for(int i = 1; i <= n; i++) s_in[i] = s_in[i - 1] + in[i];
    for(int i = 1; i <= n; i++) s_out[i] = s_out[i - 1] + out[i];

    int ans = 1;
    for(int i = 1; i <= n; i++) ans = ans * fi[c[i]] % MOD;

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int le_f = 0; le_f <= s_in[i - 1]; le_f++){
            int pu = s_out[i - 1] - (s_in[i - 1] - le_f);
            int nu = out[i];
            for(int k1 = 0; k1 <= min(pu, in[i]); k1++){
                for(int k2 = 0; k2 <= min(nu, le_f); k2++){
                    dp[i][le_f + in[i] - k1 - k2] += dp[i - 1][le_f] * P(in[i], k1) % MOD * C(pu, k1) % MOD * P(le_f, k2) % MOD * C(nu, k2) % MOD;
                    dp[i][le_f + in[i] - k1 - k2] %= MOD;
                }
            }
        }
    }

    ans = ans * dp[n][0] % MOD;
    cout << ans << endl;
}
