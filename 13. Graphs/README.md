# Table of Contents
**[Basics of Graphs](#basics-of-graphs)**
- [Graph terminology](#graph-terminology)
- [Graph representations](#graph-representations)

**[Graph traversal](#graph-traversal)**
- [Depth-first search](#dfs-depth-first-search)
- [Breadth-first search](#bfs-breadth-first-search)


# Basics of Graphs

## Graph terminology
- A graph consists of nodes and edges
- A path leads from node a to node b through edges of the graph. The length of a path is the number of edges in it.
- A path is simple if each node appears at most once in the path.
    - No edge starts and ends at the same node
    - No multiple edges between nodes
- A path is a cycle if the first and last node is the same. 

#### Connectivity 
- The connected parts of a graph are called its components
- A tree is a connected graph that consists of n nodes and n−1 edges. There is a unique path between any two nodes of a tree.
    - No cycles => Tree

#### Edges
- A graph is directed if the edges can be traversed in one direction only.
- In a weighted graph, each edge is assigned a weight. The weights are often interpreted as edge lengths.
- A graph is simple if no edge starts and ends at the same node, and there are no multiple edges between two nodes.

#### Neighbours and degrees
- Two nodes are neighbors or adjacent if there is an edge between them. The degree of a node is the number of its neighbors.
- The sum of degrees in a graph is always 2m, where m is the number of edges, because each edge increases the degree of exactly two nodes by one. For this reason, the sum of degrees is always even.
- A graph is regular if the degree of every node is a constant d. A graph is complete if the degree of every node is n−1.
- In degree : number of edges coming into a node, vice versa for out degree

#### Colouring
- In a coloring of a graph, each node is assigned a color so that no adjacent nodes have the same color.
- A graph is <strong>bipartite</strong> if it is possible to color it using two colors. 
    - A graph is bipartite exactly when it does not contain a cycle with an odd number of edges.

### Graph representations
#### Adjacency matrix

```c++
int adj[MAXN][MAXN];
int n, m; cin >> n >> m;    // Number of nodes and edges
for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;   // 0 indexing
    adj[u][v] = 1;  // Set w if graph is weighted
    adj[v][u] = 1;  // Omit this line if the graph is directed
}
```
#### Adjacency list
```c++
int n, m; cin >> n >> m;
vector<int> adj[N];     // vector<pair<int,int>> adj[N] for weighted graph
for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);    // adj[a].push_back({b, w}) for weighted graph
    adj[v].push_back(u);    // Omit this line if the graph is directed
}
```


# Graph traversal
## DFS (Depth First Search)

## BFS (Breadth First Search)

