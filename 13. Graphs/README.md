# Graphs

## Table of Contents
1. [Graph Traversal](#graph-traversal)
2. [Basic Algorithms](#basic-algorithms)
    - [Topological Sorting](#topological-sorting)
    - [Cycle Detection](#cycle-detection)
    - [Bipartite Graph](#bitpartite-graph)
3. [Shortest Paths](#shortest-paths)
    - [Dijkstra's Algorithn](#dijkstra's-aglorithm)
    - [Floyd Warshall](#floyd-warshall)
    - [Bellman Ford](#bellman-ford)



## Graph Traversal
### DFS (Depth First Search)
```c++
void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            
            dfs(v);
        }
    }
}
```

### BFS (Breadth First Search)

```c++
void bfs(int startNode, vector<vector<int>>& adj){
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int neighbour : adj[current]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
```
### Applications

#### For 2D Grids
```cpp
vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dy = {-1, 0, 1, -1. 1, -1, 0, 1};

bool isValid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Inside traversal function
for(int i = 0; i < 8; i++){
    int newX = x + dx[i];
    int newY = y + dy[i];

    if(isValid(newX, newY, n, m) && !vis[newX][newY]){
        // process node
    }
}
```
#### Finding path
```cpp
p[start_node] = -1;

p[neighbour] = p[node];     // Inside traversal function

if(!vis[u]){
    cout << "No Path";
    return;
}
vector<int> path;
for(int v = u; v != -1; v = p[v]){
    path.push_back(v);
}
reverse(path.begin(), path.end());
```

## Basic Algorithms
### Topological Sorting
- Linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.
    - Input: V = 6, edges = [[2, 3], [3, 1], [4, 0], [4, 1], [5, 0], [5, 2]]
    - Output: 5 4 2 3 1 0

#### DFS Implementation
```cpp
void toposort(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans){
    vis[u] = true;

    for(auto v : adj[u]){
        if(!vis[v]){
            toposort(v, adj, vis, ans);
        }
    }
    ans.push_back(u);
}

for(int i = 0; i < n; i++){
    if(!vis[i]){
        toposort(i, adj, vis, ans);
    }
}
reverse(ans.begin(), ans.end());
```

#### Kahn's Algorithm
```cpp
vector<int> topologicalSort(int n, vector<vector<int> >& adj){
    vector<int> indeg(n);
    for (int i = 0; i < n; i++) {
        for (auto u : adj[i]) {
            indeg[u]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (auto v : adj[node]) {
            indeg[v]--;

            if (indeg[v] == 0)
                q.push(v);
        }
    }

    if (result.size() != n) {
        cout << "Graph contains cycle";
        return {};
    }

    return result;
}
```

### Cycle Detection
