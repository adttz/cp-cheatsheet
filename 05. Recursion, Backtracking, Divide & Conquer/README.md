# Recursion

# Backtracking 

<details>
    <summary>Number of solutions to N-Queens</summary>

```cpp
int n;
vector<int> queen(n);   // queen[i] = j -> queen in row i placed in column j

bool isvalid(int level, int col){
    for(int i = 0; i < row; i++){
        int previous_row = i;
        int previous_col = queen[i];
        if(previous_col == col || abs(previous_row - row) == abs(previous_col - col)){
            return false;
        }
    }
    return true;
}

int dp(int level){
    if(level == n){
        return 1;
    }
    int ans = 0;
    for(int col = 0; col < n; col++){
        if(isvalid(level, col)){
            queen[level] = col;
            ans += dp(level + 1, n);
            queen[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << dp(0) << '\n';
}
```
</details>

# Divide & Conquer