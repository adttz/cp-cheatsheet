# Data Structures

## Table of Contents
1. [Disjoint Set Union](#1-disjoint-set-union)
2. [Segment Tree](2-segment-tree)

## 1. Disjoint Set Union
```cpp
class DSU{
    private:
        vector<int> par, rank, sz;
    public:
        DSU(int n){
            rank.resize(n + 1, 0);
            sz.resize(n + 1, 1);
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

        int size(int u){
            return sz[find[u]];
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
                if (rank[a] < rank[b]) {
                  par[a] = b;
                } 
                else if (rank[a] > rank[b]) {
                    par[b] = a;
                }
                else {
                    par[b] = a;
                    rank[a]++;
                }
            }
        }
};



// Usage
void solve(int n){
    DSU union_find(n);
    union_find.union_by_size(a, b);
    int sz = union_find.size(a);
    ...
}
```
