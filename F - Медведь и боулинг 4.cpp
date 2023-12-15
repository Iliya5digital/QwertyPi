#include <bits/stdc++.h>
#define int long long

const int N = 2e5 + 11;
const int INF = 1LL << 60;
int a[N], s[N], ss[N];

using namespace std;

deque<pair<int, int>> v;

bool interX(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	return (__int128_t) (p2.second - p1.second) * (p1.first - p3.first) >= (__int128_t) (p3.second - p1.second) * (p1.first - p2.first);
}

void add(int m, int c){
	while(v.size() >= 2 && interX({m, c}, v[0], v[1])) v.pop_front();
	v.push_front({m, c});
}

int f(pair<int, int> p, int x){
	return p.first * x + p.second;
}

int qry(int x){
	int res = -INF;
	int l = 0, r = v.size() - 1;
	while(l + 2 < r){
		int m = (l + r) / 2;
		if(f(v[m], x) >= f(v[m + 1], x)){
			r = m + 1;
		}else{
			l = m;
		}
	}
	for(int i = l; i <= r; i++) res = max(res, f(v[i], x));
	return res;
}

int32_t main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + a[i];
	}
	for(int i = 0; i < n; i++){
		ss[i + 1] = ss[i] + a[i] * (i + 1);
	}
	
	int ans = 0;
	add(0, -INF);
	for(int l = 0; l <= n; l++){
		ans = max(ans, ss[l] + qry(s[l]));
		add(-l, -ss[l] + s[l] * l);
	}
	cout << ans << endl;
}
