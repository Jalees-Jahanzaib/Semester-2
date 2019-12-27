#include<bitset/stdc++.h>
using namespace std;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}
int main(){
    vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;


}