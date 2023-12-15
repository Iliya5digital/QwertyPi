#include <bits/stdc++.h>

using namespace std;

bool dp[201][201];
int32_t main(){
    int n; cin >> n;
    string s; cin >> s;
    string ans; ans.resize(n);
    char c = 'a' - 1;
    for(int i = 0; i < n; i++){
        if(s[i] >= c) c = s[i], ans[i] = '0';
        else ans[i] = '1';
    }

    string t1, t2;
    for(int i = 0; i < n; i++){
        if(ans[i] == '0') t1.push_back(s[i]);
        else t2.push_back(s[i]);
    }

    if(is_sorted(t1.begin(), t1.end()) && is_sorted(t2.begin(), t2.end())){
        cout << "YES" << endl;
        cout << ans << endl;
        return 0;
    }

    cout << "NO" << endl;
}
