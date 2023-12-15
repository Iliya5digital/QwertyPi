#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(k % 2 == 1){
        string t1, t2;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) t1.push_back(s[i]);
            else t2.push_back(s[i]);
        }
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) cout << t1[i / 2];
            if(i % 2 == 1) cout << t2[i / 2];
        }
        cout << endl;
    }else{
        sort(s.begin(), s.end());
        cout << s << endl;
    }
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
