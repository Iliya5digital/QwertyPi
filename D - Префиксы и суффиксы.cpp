#include <bits/stdc++.h>
#define SEPERATOR "*******************"
using namespace std;

vector<int> hashing(string s){
	int n = s.size();
	vector<int> h(n + 1);
	const int p = 91203, m = 1e9 + 7; 
	for(int i = 0; i < n; i++){
		h[i + 1] = ((h[i] * p) + s[i] - 'a') % m;
	}
	return h;
}

vector<int> prefix_function(string s){
	int n = s.size();
	vector<int> pi(n);
	for(int i = 1; i < n; i++){
		int j = pi[i - 1];
		while(j && s[i] != s[j])
			j = pi[j - 1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

vector<int> z_function(string s){
	int n = s.size();
	vector<int> z(n);
	int l = -1, r = -1;
	for(int i = 1; i < n; i++){
		int z0 = 0;
		if(i < r) z0 = min(z[i - l], r - i);
		while(i + z0 < n && s[z0] == s[i + z0]) z0++;
		if(i + z0 > r) l = i, r = i + z0;
		z[i] = z0;
	}
	return z;
}

void counting_sort(vector<int>& pn, vector<int>& cn, const vector<int>& p, const vector<int>& c){
	int n = c.size(); int M = max(256, n);
	vector<int> cnt(M); pn.resize(n);
	for(int i = 0; i < n; i++){
		cnt[c[i]]++;
	}
	for(int i = 1; i < M; i++){
		cnt[i] += cnt[i - 1];
	}
	for(int i = n - 1; i >= 0; i--){
		pn[--cnt[c[i]]] = p[i];
	}
	cn[0] = 0;
	for(int i = 1; i < n; i++){
		cn[i] = cn[i - 1] + (c[pn[i - 1]] != c[pn[i]]);
	}
}

void out(vector<int> v){
	for(auto i : v) cout << i << ' '; cout << endl;
}

vector<int> suffix_array(string s){
	s += '$';
	int n = s.size();
	vector<int> pn(n), cn(n), p(n), c(n);
	for(int i = 0; i < n; i++){
		c[i] = s[i]; p[i] = i;
	}
	counting_sort(pn, cn, p, c);
	for(int h = 1; h < n; h <<= 1){
		vector<int> ipn(n); for(int i = 0; i < n; i++) ipn[pn[i]] = i;
		for(int i = 0; i < n; i++) p[i] = (pn[i] - h + n) % n;
		for(int i = 0; i < n; i++) c[i] = cn[ipn[p[i]]];
		counting_sort(pn, cn, p, c);
	}
	return pn;
}

int32_t main(){
	string s; cin >> s;
	int n = s.size();
	vector<int> pi = prefix_function(s);
	vector<int> cnt(n + 1);
	for(int i = 0; i < n; i++){
		cnt[pi[i]]++;
	}
	for(int i = n; i >= 1; i--){
		cnt[pi[i - 1]] += cnt[i];
	}
	for(int i = 1; i <= n; i++){
		cnt[i]++;
	}
	
	vector<pair<int, int>> v;
	
	int x = n;
	v.push_back({x, cnt[x]});
	while(true){
		x = pi[x - 1];
		if(x == 0) break;
		v.push_back({x, cnt[x]});
	}
	reverse(v.begin(), v.end());
	cout << v.size() << endl;
	for(auto [p, c] : v){
		cout << p << ' ' << c << endl;
	}
}
