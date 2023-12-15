#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 4e5 + 11;
int d[N];
string f(const string& B, const string& P) {
    int n = B.size(); assert(P.size() == n);
    string res(n, ' ');
    d[0] = 0; for(int i = 0; i < n; i++) d[i + 1] = d[i] + (P[i] == '(' ? 1 : -1);
    for(int i = 0; i < n; i++){
        bool flip = false;
        flip |= P[i] == '(' && d[i + 1] % 2 == 1;
        flip |= P[i] == ')' && d[i + 1] % 2 == 0;
        res[i] = flip ? '0' + '1' - B[i] : B[i];
    }
    return res;
}

string f1(vector<bool> b){
    int n = b.size() + 1;
    string res;
    for(int i = 0; i < n; i++){
        res += "()";
    }
    for(int i = 0; i < n - 1; i++){
        if(b[i]) swap(res[i * 2 + 1], res[i * 2 + 2]);
    }
    return res;
}

vector<string> ans;
int n; string s;
void try_once(){
    vector<bool> flip(n - 1);
    for(auto& c : s) c = '0' + '1' - c;
    string op2 = "(";
    for(int i = 1; i < n; i += 2){
        if(s[i] != s[i + 1]){
            if(op2.back() == '(' ^ s[i] != s[i - 1]){
                flip[i / 2] = true;
                s[i] = '0' + '1' - s[i];
                s[i + 1] = '0' + '1' - s[i + 1];
            }
            op2 += "((";
        }else{
            if(s[i] == s[i - 1]){
                op2 += '(' + ')' - op2.back();
                op2 += '(' + ')' - op2.back();
            }else{
                op2 += op2.back();
                op2 += '(' + ')' - op2.back();
            }
        }
    }
    if(op2.size() > n) op2.pop_back();
    int d = count(op2.begin(), op2.end(), '(') - count(op2.begin(), op2.end(), ')');
    for(int i = n; i < n * 2; i++){
        if(d > 0){
            op2 += ")"; d--;
        }else{
            op2 += "("; d++;
        }
    }
    string op1 = f1(flip);
    // cout << op1 << endl;
    // cout << s << endl;
    // cout << op2 << endl;
    s = f(s, op2);
    // cout << s << endl;
    ans.push_back(op1);
    ans.push_back(op2);
}
void solve(){
    ans.clear();
    cin >> n;
    cin >> s;
    string S = s;
    int c1 = 0; for(int i = 0; i < n * 2; i++) if(s[i] == '1') c1++;
    if(c1 % 2 == 1 || s[0] != s[n * 2 - 1]){
        cout << -1 << '\n';
        return;
    }

    try_once();
    reverse(s.begin(), s.end());
    try_once();
    reverse(ans[2].begin(), ans[2].end()); for(auto& c : ans[2]) c = '(' + ')' - c;
    reverse(ans[3].begin(), ans[3].end()); for(auto& c : ans[3]) c = '(' + ')' - c;
    reverse(s.begin(), s.end());
    
    int L = n * 2, R = 0;
    for(int i = 0; i + 1 < n * 2; i++){
        if(s[i] != s[i + 1]) L = min(L, i), R = max(R, i + 1);
    }
    if(L % 2 == 1) --L;
    if(R % 2 == 0) ++R;

    if(L != n * 2){
        string op3;
        for(int i = 0; i < L / 2; i++){
            op3 += "()";
        }
        for(int i = 0; i < (R - L + 1) / 2; i++){
            op3 += "(";
        }
        for(int i = 0; i < (R - L + 1) / 2; i++){
            op3 += ")";
        }
        for(int i = R / 2 + 1; i < n; i++){
            op3 += "()";
        }
        ans.push_back(op3);
        s = f(s, op3);
    }

    {
        vector<bool> flip(n - 1);
        for(int i = 0; i < n - 1; i++){
            if(s[i * 2 + 1] != s[0]){
                flip[i] = true;
            }
        }
        string op4 = f1(flip);
        ans.push_back(op4);
        s = f(s, op4);
    }

    {
        if(s[0] == '1'){
            vector<bool> flip(n - 1);
            string op5 = f1(flip);
            ans.push_back(op5);
            s = f(s, op5);
        }
    }

    for(auto c : s){
        if(c != '0'){
            cout << -1 << '\n';
            return;
        }
    }
    assert(ans.size() <= 10);
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i << '\n';
    }
}

int32_t main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
