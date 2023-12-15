#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N = 251;
char c[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int a[N][N];
int id[N][N];

int n, m, p, q; 
bool in(int i, int j){
    return 0 <= i && i < n && 0 <= j && j < m && c[i][j] != '*';
}

int32_t main(){
    cin >> n >> m >> p >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int cid = i * m + j + 1;
            if(c[i][j] < 'A' || c[i][j] > 'Z') continue;
            int pw = (c[i][j] - 'A' + 1) * p;
            int x = i, y = j;
            deque<pair<pair<int, int>, int>> V;
            V.push_back({{x, y}, pw}); id[x][y] = cid;
            while(V.size()){
                auto [pt, _pw] = V.front(); V.pop_front();
                a[pt.fi][pt.se] += _pw; 
                for(int d = 0; d < 4; d++){
                    int nx = pt.fi + dx[d], ny = pt.se + dy[d];
                    if(in(nx, ny) && _pw > 1 && id[nx][ny] != cid){
                        V.push_back({{nx, ny}, _pw / 2}); id[nx][ny] = cid;
                    }
                }
            }
        }
    }


    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt += a[i][j] > q;
        }
    }
    cout << cnt << endl;
}
