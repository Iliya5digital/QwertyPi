#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacencyList;
vector<bool> visited;

void dfs(int node, vector<int>& subtreeSizes) {
    visited[node] = true;
    subtreeSizes[node] = 1;

    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, subtreeSizes);
            subtreeSizes[node] += subtreeSizes[neighbor];
        }
    }
}

string determineWinner(int n) {
    vector<int> subtreeSizes(n + 1, 0);

    // Calculate subtree sizes for each node using DFS
    dfs(1, subtreeSizes);

    // Check if any subtree size is odd
    for (int i = 1; i <= n; i++) {
        if (subtreeSizes[i] % 2 == 0) {
            // If a subtree size is even, Alice can always make a move to create an odd-sized subtree
            return "Alice";
        }
    }

    // If all subtree sizes are odd, Bob has no valid move to make.
    return "Bob";
}

int main() {
    int n;
    cin >> n;

    adjacencyList.resize(n + 1);
    visited.resize(n + 1, false);

    // Read the edges of the tree
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        // Add the edges to the adjacency list
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    string winner = determineWinner(n);
    cout << winner << endl;

    return 0;
}
