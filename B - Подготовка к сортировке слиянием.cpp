#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a;
    a.emplace_back(vector<int>());
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        int l=0,r=(int)a.size()-1;
        while(l<r) {
            int mid=(l+r)>>1;
            if(a[mid].empty()||a[mid].back()<x) r=mid;
            else l=mid+1;
        }
        if(a[r].empty()) a.emplace_back(vector<int>());
        a[r].emplace_back(x);
    }
    for(int i=0;i<(int)a.size()-1;i++) {
        for(auto x:a[i]) cout<<x<<' ';
        cout<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
