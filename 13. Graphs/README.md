# Graphs

## Table of Contents
1. [Graph Traversal](#1-graph-traversal)
2. [Basic Algorithms](#2-basic-algorithms)
    - [Topological Sorting](#topological-sorting)
    - [Cycle Detection](#cycle-detection)
    - [Bipartite Graph](#bipartite-graph)
3. [Shortest Paths](#3-shortest-paths)
    - [Dijkstra's Algorithm](#dijktras-algorithm)
    - [Floyd Warshall](#floyd-warshall)
    - [Bellman Ford](#bellman-ford)



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


### Dijktra's Algorithm
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
- When edge weights are 0 or 1
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