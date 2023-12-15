#include <bits/stdc++.h>
#define int long long
using namespace std;

// stragetically miss math problem every time

const int MOD = 998244353;
const int root = 565042129;
const int root_1 = 950391366;
const int root_pw = 1 << 20;

const int N = (1 << 20) + 11;
int fact[N], fi[N];
int pm(int a, int b){
    if(b == 0) return 1;
    return pm(a * a % MOD, b / 2) * (b % 2 ? a : 1) % MOD;
}
int mi(int a){
    return pm(a, MOD - 2);
}

int C(int n, int r){
    if(r > n || r < 0) return 0;
    return fact[n] * fi[r] % MOD * fi[n - r] % MOD;
}

int norm(int x){
    return (x % MOD + MOD) % MOD;
}

ostream& out(ostream& out, __int128_t x){
    string s;
    while(x) s.push_back('0' + x % 10), x /= 10;
    return out << s;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = wlen * wlen % MOD;

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = a[i + j + len / 2] * w % MOD;
                a[i + j] = norm(u + v);
                a[i + j + len / 2] = norm(u - v);
                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        int n_1 = mi(n); for (int& x : a) x = x * n_1 % MOD;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i] % MOD;
    fft(fa, true);
    return fa;
}

int dp[N][21], dp2[N][21];
int32_t main(){
    fact[0] = 1; fi[0] = 1; for(int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD, fi[i] = mi(fact[i]);
    int n; cin >> n;
    int b = pm(2, n); for(int i = 1; i <= n - 1; i++) b = b * fact[1 << i] % MOD;
    dp[0][0] = 1;
    for(int l = 1; l < n; l++){
        for(int i = 0; i < (1 << l); i++){
            dp2[i][l - 1] = dp[i][l - 1] * C((1 << l) - 1, i) % MOD;
        }
        vector<int> a(1 << l), b(1 << l);
        for(int i = 0; i < (1 << l); i++) a[i] = dp2[i][l - 1];
        for(int i = 0; i < (1 << l); i++) b[i] = C((1 << l) - 1, i);
        vector<int> c = multiply(a, b);
        for(int i = 0; i < (1 << l + 1); i++) dp[i][l] = c[i];
        for(int i = 0; i < (1 << l + 1); i++){
            dp[i][l] = dp[i][l] * C((1 << l + 1) - 2, (1 << l) - 1) % MOD * mi(C((1 << l + 1) - 2, i)) % MOD;
        }
    }
    for(int i = 0; i < (1 << n); i++){
        cout << dp[(1 << n) - i - 1][n - 1] * b % MOD << '\n';
    }
}
