#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 11;
int a[MAXN];
int lp[MAXN * 2];

bool is_pr(int x){
    return lp[x] == x;
}

int32_t main(){
    for(int i = 2; i < MAXN * 2; i++){
        if(lp[i] == 0){
            lp[i] = i;
            for(int j = i * i; j < MAXN * 2; j += i){
                if(!lp[j]) lp[j] = i;
            }
        }
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int c1 = count(a, a + n, 1);
    int a1 = -1;
    for(int i = 0; i < n; i++){
        if(a[i] != 1){
            if(is_pr(1 + a[i])){
                a1 = a[i];
            }
        }
    }

    int ans = 0;
    ans = max(ans, c1 + (a1 != -1));

    if(ans >= 2){
        cout << ans << endl;
        for(int i = 0; i < c1; i++){
            cout << 1 << ' ';
        }
        if(a1 != -1) cout << a1 << ' ';
        cout << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(is_pr(a[i] + a[j])){
                cout << 2 << endl;
                cout << a[i] << ' ' << a[j] << endl;
                return 0;
            }
        }
    }

    cout << 1 << endl;
    cout << a[0] << endl;
}
