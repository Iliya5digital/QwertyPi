#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define forn(i, n) for(int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long double LD;
typedef long long LL;

const int INF = 1LL << 60;
const int MOD = 998244353;
using namespace std;

const int N = 33;
bool g[N][N];
bool r[N][N];
int n;

bool guess(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << g[i][j];
        }
        cout << '\n';
    }
    cout.flush();
    string verdict;
    cin >> verdict;
    if(verdict == "CORRECT") return true;
    for(int i = 0; i < n - 2; i++){
        string s; cin >> s;
        for(int j = 0; j < n - 2; j++){
            r[i][j] = s[j] - '0';
        }
    }
    return false;
}

void solve(){
    mt19937 rng(42);
    cin >> n;
    if(n == 3){
        do{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    g[i][j] = rng() % 2;
                }
            }
        }while(!guess());
    }else{
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = 0;
        g[2][2] = 1;
        if(guess()) return;
        bool b[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                b[2 - i][2 - j] = r[i][j];
            }
        }
        for(int msk = 0; msk < (1 << 9); msk++){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    g[i][j] = (msk & (1 << (i % 3) * 3 + (j % 3))) > 0;
                }
            }
            bool failed = false;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    int cnt = 0;
                    for(int di = 0; di < 3; di++){
                        for(int dj = 0; dj < 3; dj++){
                            cnt += g[i + di][j + dj] && b[di][dj];
                        }
                    }
                    if(cnt % 2 == 0) failed = true;
                }
            }
            if(!failed){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        g[i][j] = (msk & (1 << (i % 3) * 3 + (j % 3))) > 0;
                    }
                }
                assert(guess());
                return;
            }
        }
        for(int msk = 0; msk < (1 << 16); msk++){
            for(int i = 0; i < min(7LL, n); i++){
                for(int j = 0; j < min(7LL, n); j++){
                    g[i][j] = (msk & (1 << (i % 4) * 4 + (j % 4))) > 0;
                }
            }
            bool failed = false;
            for(int i = 0; i < min(7LL, n) - 2; i++){
                for(int j = 0; j < min(7LL, n) - 2; j++){
                    int cnt = 0;
                    for(int di = 0; di < 3; di++){
                        for(int dj = 0; dj < 3; dj++){
                            cnt += g[i + di][j + dj] && b[di][dj];
                        }
                    }
                    if(cnt % 2 == 0) {
                        failed = true;
                        break;
                    }
                }
                if(failed) break;
            }
            if(!failed){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        g[i][j] = (msk & (1 << (i % 4) * 4 + (j % 4))) > 0;
                    }
                }
                assert(guess());
                return;
            }
        }
        assert(0);
    }
}

int32_t main(){
    // cin.tie(0); cout.tie(0)->sync_with_stdio(false);
    int t = 333;
    // cin >> t;
    while(t--){
        solve();
    }
}
