#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(string a, string b, int c, int d){
	set<char> sa; for(auto i : a) sa.insert(i);
	int cnt = 0; for(auto j : b) if(sa.count(j)) cnt++;
	int c2 = 0; for(int i = 0; i < 4; i++) if(a[i] == b[i]) c2++;
	if(c2 == c && cnt - c2 == d) return true;
	return false;
}

void solve(){
	int n; cin >> n;
	vector<string> vs;
	vector<int> cnt;
	for(int i = 0; i < 10000; i++){
		int v = i; int v2 = v;
		string t; 
		set<int> s; for(int j = 0; j < 4; j++) s.insert(v % 10), t.push_back('0' + v % 10), v /= 10;
		if(s.size() == 4) vs.push_back(t);
	}
	cnt.resize(vs.size());
	for(int i = 0; i < n; i++){
		string a; int b, c; cin >> a >> b >> c;
		for(int j = 0; j < vs.size(); j++){
			cnt[j] += check(vs[j], a, b, c);
		} 
	}
	
	vector<string> cr;
	for(int i = 0; i < vs.size(); i++){
		if(cnt[i] == n) cr.push_back(vs[i]);
	}
	
	if(cr.size() == 0){
		cout << "Incorrect data" << endl;
	}else if(cr.size() == 1){
		cout << cr[0] << endl;
	}else{
		cout << "Need more data" << endl;
	}
}

int32_t main(){
	int t; t = 1;
	while(t--){
		solve(); 
	}
}
