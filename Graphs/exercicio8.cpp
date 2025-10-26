#include <iostream>  
#include <vector>     

using namespace std;

const int MAXN = 150005;

vector<int> adj[MAXN];

bool visitado[MAXN];

int no = 0, arestas = 0;

void dfs(int u) {
    visitado[u] = true;    
    no++;              
    arestas += adj[u].size(); 

    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  
        adj[b].push_back(a);  
    }

    for (int i = 1; i <= n; ++i) {
        if (!visitado[i]) {
            no = 0;
            arestas = 0;
            dfs(i);  

            if (1LL * no * (no - 1) != arestas) {
                cout << "NO" << endl;  
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
