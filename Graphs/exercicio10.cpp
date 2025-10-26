#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN]; 
int subordinates[MAXN]; 

int dfs(int node) {
    int count = 0;

    for (int child : adj[node]) {
        count += 1 + dfs(child); 
    }

    subordinates[node] = count;
    return count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i); 
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    cout << endl;

    return 0;
}