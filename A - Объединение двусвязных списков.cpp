#include <bits/stdc++.h>

using namespace std;

const int N = 111;
int l[N], r[N];
int32_t main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    vector<vector<int>> links;
    for(int i = 1; i <= n; i++){
        if(l[i] == 0){
            int x = i;
            vector<int> v {x};
            while(r[x]){
                v.push_back(r[x]);
                x = r[x];
            }
            links.push_back(v);
        }
    }
    vector<int> a;
    for(auto i : links) for(auto j : i) a.push_back(j);
    fill(l, l + N, 0); fill(r, r + N, 0);
    for(int i = 0; i + 1 < a.size(); i++){
        r[a[i]] = a[i + 1]; l[a[i + 1]] = a[i];
    }
    for(int i = 1; i <= n; i++){
        cout << l[i] << ' ' << r[i] << '\n';
    }
}
