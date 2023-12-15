#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k,m,a;
    cin>>n>>k>>m>>a;
    vector<int> num(n+2),last(n+2);
    for(int i=1;i<=a;i++) {
        int x;
        cin>>x;
        num[x]++;
        last[x]=i;
    }
    if(n==k) {
        for(int i=1;i<=n;i++)
            if(num[i]!=0) cout<<1<<' ';
            else if(m-a!=0) cout<<2<<' ';
            else cout<<3<<' ';
        cout<<'\n';
        return;
    }
    vector<int> p(n+2);
    iota(p.begin(),p.end(),0);
    sort(p.begin()+1,p.end()-1,[&](int x,int y) { return num[x]>num[y]||(num[x]==num[y]&&last[x]<last[y]); });
    for(int i=1;i<=n;i++) {
        bool win=false,lose=false;
        int idx=find(p.begin()+1,p.end()-1,i)-p.begin();
        if(idx<=k&&num[i]!=0) {
            win=true;
            int sum=0;
            for(int j=idx+1;j<=k+1;j++) sum+=num[i]+1-num[p[j]];
            if(sum<=m-a) lose=true;
        }
        else {
            lose=true;
            if(num[i]+m-a>num[p[k]]) win=true;
        }
        if(win&&lose) cout<<2<<' ';
        else if(win) cout<<1<<' ';
        else cout<<3<<' ';
    }
    cout<<'\n';
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
