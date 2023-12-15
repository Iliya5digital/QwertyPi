#include <bits/stdc++.h>
using namespace std;

template<class T>
struct dinic{
    int size;

    struct Edge{
        int to;
        T cap;
        int rev;

        Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {};
    };

    vector<vector<Edge>> graph;
    vector<int> dist;
    vector<bool> isTrav;
    vector<int> cur;

    int sink;
    bool bfs(int s, int t) {
        for (int i = 0; i < size; i++) { isTrav[i] = 0; dist[i] = 0; cur[i] = 0; }

        queue<int> q;
        isTrav[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < (int)graph[now].size(); i++) {
                int toNode = graph[now][i].to;
                if (!isTrav[toNode] && graph[now][i].cap > 0) {
                    isTrav[toNode] = 1;
                    q.push(toNode);
                    dist[toNode] = dist[now] + 1;
                    if (toNode == t) return 1;
                }
            }
        }
        return 0;
    }

    T dfs(int node, T flow) {
        if (node == sink) return flow;

        for (int& i = cur[node]; i < (int)graph[node].size(); i++) {
            int toNode = graph[node][i].to;

            if (dist[toNode] == dist[node] + 1 && graph[node][i].cap > 0) {
                T toflow = dfs(toNode, min(flow, graph[node][i].cap));
                if (toflow) {
                    graph[node][i].cap -= toflow;
                    graph[toNode][graph[node][i].rev].cap += toflow;
                    return toflow;
                }
            }
        }
        return 0;
    }

public:
    T maxflow(int s, int t) {
        sink = t;
        T flow = 0;
        while (bfs(s, t)) {
            while (true) {
                T newflow = dfs(s, 1e9);
                if (newflow)
                    flow += newflow;
                else
                    break;
            }
        }
        return flow;
    }

    void addedge(int u, int v, T cap) {
        Edge a(v, cap, graph[v].size());
        Edge b(u, 0, graph[u].size());
        graph[u].push_back(move(a));
        graph[v].push_back(move(b));
    }

    dinic(int size) : size(size) {
        graph.resize(size);
        dist.resize(size);
        isTrav.resize(size);
        cur.resize(size);
    }
};

int main(){
    int n, m; cin >> n >> m;
    dinic<int> f(n + m + 10);
    int s = n + m + 1, t = n + m + 2;

    for(int i = 1; i <= m; i++){
        f.addedge(n + i, t, 1);
    }

    vector<pair<int, int>> E;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        E.push_back({u, v});
        f.addedge(u, n + i, 1);
        f.addedge(v, n + i, 1);
    }

    int F = 0, ans = 0;
    while(F < m){
        ans++;
        for(int i = 1; i <= n; i++){
            f.addedge(s, i, 1);
        }
        F += f.maxflow(s, t);
    }
    cout << ans << endl;
    for(int i = 1; i <= m; i++){
        int v = -1;
        for(auto [to, cap, rev] : f.graph[n + i]){
            if(cap == 0 && to != t) v = to;
        }
        cout << (E[i - 1].first + E[i - 1].second - v) << ' ' << v << '\n';
    }
}
