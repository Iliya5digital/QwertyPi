#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=n*2;
    while(l<r) {
        int mid=(l+r)>>1;

        auto check = [&]() {
            set<int> stars;
            vector<int> pacmans;
            for(int i=0;i<n;i++)
                if(s[i]=='*') stars.emplace(i);
                else if(s[i]=='P') pacmans.emplace_back(i);
            for(auto i:pacmans) {
                if(stars.empty()) break;
                if(i-*stars.begin()>mid) return false;
                int k=min(i,*stars.begin());
                auto it=stars.begin();
                while(it!=stars.end()&&(*it<i||(*it>i&&*it-k+min(*it-i,i-k)<=mid))) it++;
                stars.erase(stars.begin(),it);
            }
            return stars.empty();
        };

        if(check()) r=mid;
        else l=mid+1;
    }
    cout<<r<<'\n';
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
