#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 11;
vector<int> G[N], H[N];

bool vis[N];
bool cc[N][N];
vector<int> tp;

void dfs(int v = 1){
    vis[v] = true;
    for(auto u : G[v]){
        if(!vis[u]) dfs(u);
    }
    tp.push_back(v);
}

vector<vector<int>> ccs[N];

vector<pair<int, int>> ans;

void add_edge(int u, int v){
    ans.push_back({u, v});
    H[u].push_back(v);
    H[v].push_back(u);
}

vector<int> Li;
void dfs2(int rt, int v){
    Li.push_back(v); vis[v] = true;
    for(auto u : H[v]){
        if(!vis[u]) dfs2(rt, u);
    }
}

int32_t main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        vector<int> sep {-1};
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-') sep.push_back(i);
        }
        sep.push_back(s.size());
        vector<string> lists;
        for(int i = 0; i + 1 < sep.size(); i++){
            lists.push_back(s.substr(sep[i] + 1, sep[i + 1] - sep[i] - 1));
        }
        for(auto t : lists){
            vector<int> st;
            vector<int> sep;
            for(int i = 0; i < t.size(); i++){
                if(t[i] == ':') sep.push_back(i);
            }
            for(int i = 0; i < t.size(); i++){
                if(t[i] == ',') sep.push_back(i);
            }
            sep.push_back(t.size());
            for(int i = 0; i + 1 < sep.size(); i++){
                st.push_back(stoi(t.substr(sep[i] + 1, sep[i + 1] - sep[i] - 1).c_str()));
            }
            bool ex_par = false;
            for(auto u : st) if(u == 1) ex_par = true;

            if(!ex_par){
                for(auto u : st) G[i].push_back(u), cc[i][u] = true;
            }
            sort(st.begin(), st.end());
            ccs[i].push_back(st);
        }
        sort(ccs[i].begin(), ccs[i].end());
    }

    dfs(1);
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(cc[tp[j]][tp[i]]){
                add_edge(tp[i], tp[j]);
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        fill(vis, vis + n + 1, false); vis[i] = true;
        vector<vector<int>> a;
        for(auto v : H[i]){
            Li.clear(); dfs2(i, v); sort(Li.begin(), Li.end());
            a.push_back(Li);
        }
        sort(a.begin(), a.end());

        if(a != ccs[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << ' ' << i.second << '\n';
    }
}
