#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100001];

set<int> S;
map<int, int> M;

void check(int v){
	if(M[v] != 1) S.erase(v);
	else S.insert(v);
}

void get(){
	if(S.empty()){
		cout << "Nothing" << endl;
	}else{
		cout << *--S.end() << endl;
	}
}

int32_t main(){
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < k; i++){
		M[a[i]]++; 
		check(a[i]);
	}
	get();
	for(int i = 0; i < n - k; i++){
		M[a[i]]--; M[a[i + k]]++;
		check(a[i]); check(a[i + k]);
		get();
	}
}
