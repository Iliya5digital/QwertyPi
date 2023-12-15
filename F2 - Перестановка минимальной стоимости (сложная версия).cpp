#include <bits/stdc++.h>

// failed IMO, only got Bronze
// At least give me some CF rating

using namespace std;

multiset<int> S;
int n, c;
bool try_remove(multiset<int>::iterator p){
    if(p == S.begin() || p == S.end()) return false;
    if(next(p) == S.end()) return true;
    return *next(p) - *prev(p) <= c;
}

vector<int> f(vector<int> x){
    S.clear(); vector<int> a;
    for(auto i : x) S.insert(i);
    int v = *--S.end(); S.erase(--S.end());
    a.push_back(v);
    while(S.size() > 1){
        auto p = S.lower_bound(v - c);
        while(!try_remove(p)){
            ++p;
        }
        v = *p; S.erase(p);
        a.push_back(v);
    }
    if(S.size()) a.push_back(*S.begin());
    return a;
}

void solve(){
    cin >> n >> c;
    vector<int> v; for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    vector<int> ans;
    S.clear();
    for(int i = 0; i < n; i++){
        S.insert(v[i]);
    }
    
    sort(v.begin(), v.end());
    if(c >= 0){
        ans = v;
    }else{
        c = abs(c);
        vector<int> v2;
        for(auto i : v){
            if(!v2.empty() && i - v2.back() > c){
                vector<int> a = f(v2);
                reverse(a.begin(), a.end());
                for(auto i : a) ans.push_back(i);
                v2.clear();
            }
            v2.push_back(i);
        }
        vector<int> a = f(v2);
        reverse(a.begin(), a.end());
        for(auto i : a) ans.push_back(i);
        reverse(ans.begin(), ans.end());
    }
    for(auto i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int32_t main(){
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}
