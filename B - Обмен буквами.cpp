#include <bits/stdc++.h>

using namespace std;

string ss[100001];


struct datum{
    int a1, a2;
    char c1, c2;
};

vector<datum> ans;

void solve(){
    ans.clear();
    map<string, vector<int>> M;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ss[i]; sort(ss[i].begin(), ss[i].end()); M[ss[i]].push_back(i);
    }

    int req = n - M["inw"].size();
    auto check = [&M](string s1, string s2, char c1, char c2, string r1 = "", string r2 = ""){
        while(M[s1].size() && M[s2].size()){
            int a1 = M[s1].back(); M[s1].pop_back(); M[r1].push_back(a1);
            int a2 = M[s2].back(); M[s2].pop_back(); M[r2].push_back(a2);
            ans.push_back({a1, a2, c1, c2});
        }
    };

    auto check1 = [&M](string s1, string s2, char c1, char c2, string r1 = "", string r2 = ""){
        if(M[s1].size() && M[s2].size()){
            int a1 = M[s1].back(); M[s1].pop_back(); M[r1].push_back(a1);
            int a2 = M[s2].back(); M[s2].pop_back(); M[r2].push_back(a2);
            ans.push_back({a1, a2, c1, c2}); return true;
        }
        return false;
    };

    check("www", "iii", 'w', 'i', "iww", "iiw");
    check("www", "nnn", 'w', 'n', "nww", "nnw");
    check("iii", "nnn", 'i', 'n', "iin", "inn");
    check("iii", "nnw", 'i', 'n', "iin");
    check("iii", "nww", 'i', 'w', "iiw");
    check("nnn", "iiw", 'n', 'i', "inn");
    check("nnn", "iww", 'n', 'w', "nnw");
    check("www", "iin", 'w', 'i', "iww");
    check("www", "inn", 'w', 'n', "nww");
    
    while(M[""].size() != req){
        check("iin", "nww", 'i', 'w');
        check("iiw", "nnw", 'i', 'n');
        check("inn", "iww", 'n', 'w');
        if(!check1("nww", "inn", 'w', 'n', "nnw"))
        if(!check1("inn", "iiw", 'n', 'i', "iin"))
        if(!check1("iiw", "nww", 'i', 'w', "iww"))
        if(!check1("iww", "nnw", 'w', 'n', "", "nww"))
        if(!check1("nnw", "iin", 'n', 'i', "", "inn"))
        if(!check1("iin", "iww", 'i', 'w', "", "iiw"))
        ;
    }
    cout << ans.size() << endl;
    for(auto d : ans){
        cout << d.a1 + 1 << ' ' << d.c1 << ' ' << d.a2 + 1 << ' ' << d.c2 << endl;
    }
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
