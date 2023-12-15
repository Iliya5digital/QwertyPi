#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2e6 + 11;
int a[N], b[N], c[N];

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], --a[i];

    FT ft(n * 2 + 5);
    vector<int> f(n * 2 + 5, -1);
    for(int i = 0; i < n; i++){
        if(a[i] >= i) f[a[i]] = i, f[a[i] + n] = i + n;
        else f[a[i] + n] = i;
    }
    for(int i = 0; i < n * 2; i++){
        int L = f[i], R = i;
        if(L == -1) continue;
        if (L == R) {
            c[R % n] = 0;
        }else{
            int dist = R - L;
            int skip = ft.query(R) - ft.query(L + 1);
            c[R % n] = dist - skip;
        }
        ft.update(L, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
