# Basics of Graphs

### Graph terminology
- A graph consists of nodes and edges
- A path leads from node a to node b through edges of the graph. The length of a path is the number of edges in it.
- A path is simple if each node appears at most once in the path.
    - No self loops or multiple edges
- A path is a cycle if the first and last node is the same. 

### Connectivity

- **Connected Graph (Undirected)**:
    - A graph is connected if there exists a path between every pair of nodes.
    - No isolated nodes or disjoint parts.

- **Component**:
    - Maximal subgraph that is connected
    - You cannot add any more nodes to the component without breaking connectivity
    - In an undirected graph, each disconnected chunk is a component

// TODO: 
- **Strongly Connected (Directed Graph)**:

- **Weakly Connected (Directed Graph)**:

### Edges
- A graph is directed if the edges can be traversed in one direction only.
- In a weighted graph, each edge is assigned a weight. The weights are often interpreted as edge lengths.
- A graph is simple if no edge starts and ends at the same node, and there are no multiple edges between two nodes.

### Neighbours and degrees
- Two nodes are adjacent or neighbours if connected by an edge
- Degree of node = number of edges connected to it
    - In-degree: number of incoming edges
    - Out-degree: number of outgoing edges
- A graph is regular if degree of every node = constant d. A graph is complete if degree of every node = n−1.
- Handshaking Lemma
    - Undirected: `∑deg(v) = 2m`  
    - Directed: ` ∑in-deg = ∑out-deg = m`

### Colouring
- In a coloring of a graph, each node is assigned a color so that no adjacent nodes have the same color.
- A graph is bipartite if it is possible to color it using two colors. 
    - Equivalent to no odd length cycles


## Graph representation
### Adjacency matrix

```c++
int adj[MAXN][MAXN];
int n, m; cin >> n >> m;    // Number of nodes and edges
for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;               // 0 indexing
    adj[u][v] = 1;          // Set w if graph is weighted
    adj[v][u] = 1;          // Omit this line if the graph is directed
}
```
### Adjacency list
```c++
int n, m; cin >> n >> m;
vector<vector<int>> adj     // vector<vector<pair<int,int>>> adj for weighted graph
for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);    // adj[a].push_back({b, w}) for weighted graph
    adj[v].push_back(u);    // Omit this line if the graph is directed
}
```