# Dynamic Programming

## Table of Contents
1. [Introduction](#introduction)
2. [2D / Grid DP](#2d--grid-dp)
3. [Knapsack](#knapsack)
4. [DP on Subsequences](#dp-on-subsequences)
    - [Longest Increasing Subsequence](#longest-increasing-subsequence)
    - [Longest Common Subsequence](#longest-common-subsequence)
5. [String DP](#string-dp)
6. [Bitmask DP](#bitmask-dp)
7. [Digit DP](#digit-dp)
.

## 1. Introduction

### Recursive vs Iterative

#### Top-Down (Memoization)
- Check if we have solved current sub-problem
- Start from highest level of problem
- Computers only those solutions which are needed

```cpp
int func(int n) {
    if(base_case){
        return val;
    }
    if(dp[n] != -1){
        return dp[n];   // Already calculated value
    }
    int include = func(...);
    int exclude = func(...);
    return dp[n] = f(include, exclude);
}
```

#### Bottom-Up (Tabulation)
- Start at the bottom and work our way to the top 
- Calculates all solutions in the range

```cpp
int func(int n) {
    vector<int> dp(n+1);
    if(base_case){
        dp[val] = some_value;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = f(dp[i-x], dp[i-y]);
    }
    return dp[n];
}
```

## 2. 2D / Grid DP

## 3. Knapsack

### 0/1 Knapsack

```cpp
vector<<vector> dp(n+1, vector<int>(W+1));
for(int i = 1; i <= n; i++){
    for(int j = 0; j <= W; j++){
        dp[i][j] = dp[i-1][j];

        if(j >= wt[i-1]){
            dp[i][j] = max(dp[i][j], dp[i-1][j - wt[i-1]] + val[i-1]);
        }
    }
}
return dp[n][W];

// Space-Optimized
vector<int> dp(W+1, 0);
for(int i = 1; i <= n; i++){
    for(int j = W; j >= wt[i-1]; j--){
        dp[j] = max(dp[j], dp[j - wt[i-1]] + val[i-1]);
    }
}
return dp[W];
```

### Subset Sum

```cpp
vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
dp[0][0] = true;
for(int i = 1; i <= n; i++){
    for(int j = 0; j <= target; j++){
        dp[i][j] = dp[i-1][j];  
        if(j >= arr[i-1] && dp[i-1][j - arr[i-1]]){
            dp[i][j] = true;
        }
    }
}
return dp[n][target];

// Space-Optimized
vector<bool> dp(target+1, false);
dp[0] = true;
for(int i = 0; i < n; i++){
    for(int j = target; j >= arr[i]; j--){
        dp[j] |= dp[j - arr[i]];
    }
}
return dp[target];
```

### Unbounded Knapsack
```cpp
vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

for(int i = 1; i <= n; i++){
    for(int j = 0; j <= W; j++){
        dp[i][j] = dp[i-1][j];  // not take
        if(j >= wt[i-1]){
            dp[i][j] = max(dp[i][j], dp[i][j - wt[i-1]] + val[i-1]);  // take again
        }
    }
}
return dp[n][W];

// Space-Optimized
vector<int> dp(W+1, 0);
for(int i = 1; i <= n; i++){
    for(int j = wt[i-1]; j <= W; j++){
        dp[j] = max(dp[j], dp[j - wt[i-1]] + val[i-1]);
    }
}
return dp[W];
```