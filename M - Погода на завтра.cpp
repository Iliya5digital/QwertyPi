#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    int num=a[1]-a[0];
    bool ok=true;
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]!=num) {
            ok=false;
            break;
        }
    if(ok) cout<<a[n-1]+num<<'\n';
    else cout<<a[n-1]<<'\n';
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
