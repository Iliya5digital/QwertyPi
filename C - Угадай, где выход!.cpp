#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int h, n; cin >> h >> n;
    n--;

    int x = n & (1LL << h - 1);
    for(int i = 0; i < h - 1; i++){
        x += ((long long)(((n & (1LL << i)) > 0) == ((n & (1LL << i + 1)) > 0))) << i;
    }
    int ans = 0;
    for(int i = h - 1; i >= 0; i--){
        if(x & (1LL << i)){
            ans += (1LL << i + 1);
        }else{
            ans++;
        }
    }
    cout << ans << endl;
}
