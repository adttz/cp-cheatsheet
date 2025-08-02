# Data Structures

## Table of Contents
1. [Disjoint Set Union](#1-disjoint-set-union)
2. [Segment Tree](2-segment-tree)

## 1. Disjoint Set Union

### Template

```cpp
class DSU{
    private:
        vector<int> par, rank, size;
    public:
        DSU(int n){
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            par.resize(n + 1);
            for(int i = 1; i <= n; i++){
                par[i] = i;
            }
        }

        int find(int u){
            if(u == par[u]){
                return u;
            }
            return par[u] = find(par[u]);   // Path compression
        }

        int get_size(int u){
            return size[find(u)];
        }

        void union_by_size(int u, int v){
            int a = find(u);
            int b = find(v);
            if(a != b){
                if(size[a] < size[b]){
                    swap(a, b);             // Keep b smaller than a
                }
                par[b] = a;
                size[a] += size[b];
            }
        }

        void union_by_rank(int u, int v){
            int a = find(u);
            int b = find(v);
            if(a != b){
                if(rank[a] < rank[b]){
                    swap(a, b);
                }
                par[b] = a;
                if(rank[a] == rank[b]){
                    rank[a]++;
                }
            }
        }
};
```

#### Usage
```cpp
void solve(int n){
    DSU union_find(n);
    union_find.union_by_size(a, b);
    int sz = union_find.get_size(a);
    ...
}
```
#### DSU on Grid
```cpp
int rows = grid.size();
int cols = grid[0].size();
DSU dsu(rows * cols);

auto getID = [&](int i, int j) {
    return i * cols + j;    // Main logic
};

vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
        if (grid[i][j] != 1) continue;

        for (auto [dx, dy] : directions) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && nj >= 0 && ni < rows && nj < cols && grid[ni][nj] == 1) {
                dsu.unite(getID(i, j), getID(ni, nj));
            }
        }
    }
}
```