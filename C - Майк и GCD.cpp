#include <bits/stdc++.h>

using namespace std;

int a[100011];
int32_t main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int g = 0; for(int i = 0; i < n; i++) g = __gcd(g, a[i]);

    if(g > 1){
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < n;){
        if(a[i] % 2 == 0) i += 1;
        else if(i < n - 1 && a[i] % 2 == 1 && a[i + 1] % 2 == 1) ans++, i += 2;
        else ans += 2, i++;
    }
    cout << "YES" << endl;
    cout << ans << endl;
}
