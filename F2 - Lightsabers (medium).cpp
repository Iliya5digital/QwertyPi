#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 11;

int a[MAXN], b[MAXN];
int c[MAXN];
int32_t main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++) cin >> b[j];
    int s = accumulate(b + 1, b + m + 1, 0);
    int l = 0, r = 0, lack = s;
    int ans = 1 << 30;
    for(l = 0; l < n; l++){
        while(r < n && lack > 0){
            c[a[r]]++; if(c[a[r]] <= b[a[r]]) lack--;
            r++;
        }
        if(lack == 0){
            ans = min(ans, r - l - s);
        }
        c[a[l]]--; if(c[a[l]] < b[a[l]]) lack++;
    }
    cout << (ans == (1 << 30) ? -1 : ans) << endl;
}
