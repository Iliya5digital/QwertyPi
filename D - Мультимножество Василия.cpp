#include <bits/stdc++.h>

using namespace std;

struct node{
    int cnt = 0;
    node* t[2] = {};
};

node *root = new node();

int val(node* v){
    return v ? v->cnt : 0;
}

void dfs_add(node* v, int j, int x, int _val){
    if(j == -1){
        v->cnt += _val;
        return;
    }
    bool b = x & (1 << j);
    if(!v->t[b]) v->t[b] = new node();
    dfs_add(v->t[b], j - 1, x, _val);
    v->cnt = val(v->t[0]) + val(v->t[1]);
}

void solve(){
    int q; cin >> q;
    dfs_add(root, 29, 0, 1);
    for(int i = 0; i < q; i++){
        char c; int x; cin >> c >> x;
        node *v = root;
        if(c == '+'){
            dfs_add(v, 29, x, 1);
        }else if(c == '-'){
            dfs_add(v, 29, x, -1);
        }else if(c == '?'){
            int ans = 0;
            for(int j = 29; j >= 0; j--){
                bool b = (1 << j) & x;
                if(v->t[!b] && v->t[!b]->cnt) ans += (1 << j), v = v->t[!b];
                else v = v->t[b];
            }
            cout << ans << endl;
        }
    }
}

int32_t main(){
    int t; t = 1; // cin >> t;
    while(t--){
        solve();
    }
}
