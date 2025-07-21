# Graphs

## Table of Contents
1. [Graph Traversal](#1-graph-traversal)
2. [Basic Algorithms](#2-basic-algorithms)
    - [Topological Sorting](#topological-sorting)
    - [Cycle Detection](#cycle-detection)
    - [Bipartite Graph](#bipartite-graph)
3. [Shortest Paths](#3-shortest-paths)
    - [Dijkstra's](#dijkstras-algorithm)
    - [0/1 BFS](#01-bfs)
    - [Floyd-Warshall](#floyd-warshall-algorithm)
    - [Bellman-Ford](#bellman-ford-algorithm)
4. [Minimum Spanning Tree](#4-minimum-spanning-tree)
    - [Prim's Algorithm](#prims-algorithm)
    - [DSU](#dsu)
    - [Kruskal's Algorithm](#kruskals-algorithm)


## 1. Graph Traversal
### DFS (Depth First Search)
```c++
void dfs(int u){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
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
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

vector<int> dx_diag = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dy_diag = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Inside traversal function
for(int i = 0; i < 4; i++){
    int newX = x + dx[i];
    int newY = y + dy[i];
    if(isValid(newX, newY, n, m) && !vis[newX][newY]){
        // process node
    }
}
```
#### Tracing path
```cpp
p[start_node] = -1;

for(auto neighbour : adj[node]){
    p[neighbour] = node;     // Inside traversal function
}

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

## 2. Basic Algorithms
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
    for (int i = 0; i < n; i++) {
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
#### <ins> Directed Graph </ins>

- Using DFS
```cpp
bool dfs(int u, vector<int> adj[], vector<bool> &vis, vector<bool> &rec){
    vis[u] = true;
    rec[u] = true;
    
    for(auto v : adj[u]){
        if(!vis[v]){
            if(dfs(v, adj, vis, rec)) return true;
        }
        else if (rec[v]){
            return true;
        }
    }
    rec[u] = false;
    return false;
}
```

- Using Kahn's Algorithm
```cpp
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n);
    for (int i = 0; i < n; i++)
        for (auto u : adj[i])
            indeg[u]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (auto v : adj[node]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return count != n; // True if cycle exists
}
```

#### <ins> Undirected Graph </ins>
```cpp
bool dfs(int u, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u, adj, vis)) return true;
        } 
        else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = true;

    while (!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push({neighbor, node});
            } 
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}
```

### Bipartite Graph
- Number of edges in bipartite graph = colour[0] * colour[1];
#### Using BFS
```cpp
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colour(n, -1);
    for(int i = 0; i < n; i++){
        if(colour[i] != -1) continue;
        queue<int> q;
        q.push(i);
        colour[i] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto u : graph[v]){
                if(colour[u] == -1){
                    colour[u] = 1 ^ colour[v];
                    q.push(u);
                }
                else if (colour[u] == colour[v]){
                    return false;
                }
            }
        }
    }
    return true;
}
```
#### Using DFS
```cpp
bool dfs(int v, int c, vector<vector<int>> &graph, vector<int> &colour) {
    colour[v] = c;
    for (auto u : graph[v]) {
        if (colour[u] == -1) {
            if (!dfs(u, c ^ 1, graph, colour)) return false;
        } 
        else if (colour[u] == c) {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> colour(n, -1);
    for (int i = 0; i < n; i++) {
        if (colour[i] == -1) {
            if (!dfs(i, 0, graph, colour)) return false;
        }
    }
    return true;
}
```

## 3. Shortest Paths

### Dijkstra's Algorithm
- Traditional shortest path algorithm for graph with positive edges
- O((V + E) * log V) Time
```cpp
vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src}); // {dist, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue; // Skip if not optimal

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```


### 0/1 BFS 
- When edge weights are 0 or 1 only
- Speeds up Dijkstra's from O((V + E) * log V) to O(V + E)
```cpp
vector<int> zeroOneBFS(int src, int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, INT_MAX);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}
```

### Floyd-Warshall Algorithm
- Shortest path between all nodes
- O(V³) Time
```cpp
const int INF = 1e9;
vector<vector<int>> floydWarshall(int n, vector<vector<pair<int, int>>> &adj) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int u = 0; u < n; u++) {
        dist[i][i] = 0;
        for (auto [v, w] : adj[u]) {
            dist[u][v] = w;     // directed graph; for undirected: dist[v][u] = w too
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    // dist[i][i] < 0 => Negative cycle present
    return dist;    // dist[i][j] = Min dist from i to j
}
```


### Bellman-Ford Algorithm
- Single shortest path finding algo for graphs including negative weights
- O(V * E) Time
```cpp
const int INF = 1e9;
vector<int> bellmanFord(int n, int src, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++){   // Relax edges (n - 1) times
        for (int u = 0; u < n; u++){
            if (dist[u] == INF) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Detecting negative cycle
    for (int u = 0; u < n; ++u) {
        if (dist[u] == INF) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                cout << "Negative weight cycle detected" << '\n';
                break;
            }
        }
    }

    return dist;
}
```

## 4. Minimum Spanning Tree

### Prim's Algorithm
- Start from any node and pick minimum weight edge to unvisited node using min-heap
- O(E log V) Time
    - Works better than Kruskal's for dense graphs (E ≈ V²)
```cpp
int prims(int n, vector<vector<pair<int,int>>> &adj){
    vector<bool> vis(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0}); // (weight, node)

    int mst_cost = 0;
    while(!pq.empty()){
        auto [wt, u] = pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u] = true;

        mst_cost += wt;
        for(auto &[v_wt, v] : adj[u]){
            if(!vis[v]){
                pq.push({v_wt, v});
            }
        }
    }
    return mst_cost;
}
```

### DSU
// Add hyperlink here

### Kruskal's Algorithm
- Sort edges on increasing weight, add corresponding vertices to union if not in union already
- O(E log E) Time
    - Better for sparse graphs
```cpp
// DSU Class

int kruskals(int n, int m){
    DSU dsu(n);
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    int weight = 0;
    for(auto &[w, u, v] : edges){
        if(dsu.find(u) == dsu.find(v)) continue;
        weight += w;
        dsu.merge(u, v);
    }
    return weight;
}
```