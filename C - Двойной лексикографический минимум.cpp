#include <bits/stdc++.h>

using namespace std;

bool all_eq[100011];
void solve(){
    string s; cin >> s;
    sort(s.begin(), s.end());
    int l = 0, r = s.size() - 1;
    all_eq[s.size() - 1] = true;
    for(int i = (int) s.size() - 2; i >= 0; i--){
        all_eq[i] = all_eq[i + 1] && (s[i] == s[i + 1]);
    }
    bool le = true;
    string f, b;
    char single = ' ';
    while(r - l >= 1){
        if(s[l] != s[l + 1]){
            if(single == ' ') {
                single = s[l]; l++;
                if(all_eq[l]) continue;
            }
            b.push_back(single);
            while(l <= r){
                f.push_back(s[l++]);
            }
            single = ' ';
        }else{
            b.push_back(s[l++]);
            f.push_back(s[l++]);
        }
    }
    if(l == r){
        if(single == ' ') {
            f.push_back(s[l++]);
        } else {
            b.push_back(single);
            while(l <= r){
                f.push_back(s[l++]);
            }
        }
    }else if(single != ' '){
        f.push_back(single);
    }
    reverse(b.begin(), b.end());
    cout << f << b << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
