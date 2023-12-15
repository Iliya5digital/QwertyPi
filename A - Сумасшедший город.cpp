#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point{
    int x, y;
};

struct Line{
    int a, b, c;
    int f(Point p){
        return a * p.x + b * p.y + c;
    }
};

int sgn(int x){
    return x > 0 ? 1 : -1;
}

int32_t main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    Point A = {x1, y1}, B = {x2, y2};
    vector<Line> L;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        L.push_back({a, b, c});
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += sgn(L[i].f(A)) != sgn(L[i].f(B));
    }
    cout << ans << endl;
}
