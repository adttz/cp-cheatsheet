# Dynamic Programming

## Table of Contents
1. [Introduction](#1-introduction)
2. [2D / Grid DP](#2-2d--grid-dp)
3. [Knapsack](#3-knapsack)
4. [DP on Subsequences](#4-dp-on-subsequences)
    - [Longest Increasing Subsequence](#longest-increasing-subsequence)
    - [Longest Common Subsequence](#longest-common-subsequence)
5. [String DP](#string-dp)
6. [Bitmask DP](#bitmask-dp)
7. [Digit DP](#digit-dp)

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

## 4. DP on Subsequences

### <ins> Longest Increasing Subsequence </ins>

- In O(n^2)
```cpp
vector<int> lis(vector<int> const& v) {
    int n = v.size();
    vector<int> dp(n, 1), pos(n, -1);
    int maxLen = 1, idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i] && dp[i] < d[j] + 1) {
                dp[i] = max(dp[i], dp[j] + 1);
                pos[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            idx = i;
        }
    }

    vector<int> subseq;
    while (idx != -1) {
        subseq.push_back(v[idx]);
        idx = pos[idx];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}
```

- In O(nlogn)
```cpp
vector<int> getLIS(vector<int>& v) {
    int n = v.size();
    vector<int> dp;                    // stores the actual increasing elements
    vector<int> pos;                   // stores indices in v corresponding to dp
    vector<int> p(n, -1);              // predecessor array for reconstruction

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();

        if (idx == dp.size()) {
            dp.push_back(v[i]);
            pos.push_back(i);
        } 
        else {
            dp[idx] = v[i];
            pos[idx] = i;
        }
        
        // Only for reconstructing sequence
        if (idx > 0) {
            p[i] = pos[idx - 1];
        }
    }

    vector<int> res;
    int idx = pos.back();
    while (idx != -1) {
        res.push_back(v[idx]);
        idx = p[idx];
    }
    reverse(res.begin(), res.end());
    return res;
}
```

### <ins>Longest Common Subsequence</ins>
- dp[i][j] = The length of the longest common subsequence between the prefixes A[0..i-1] and B[0..j-1].
```cpp
string findLCS(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }	
    // dp[n][m] -> Length of LCS

    string s;
    while(n > 0 && m > 0){
        if(s1[n-1] == s2[m-1]){
            s += s1[n-1];
            n--; m--;
        }
        else if(dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }

    reverse(s.begin(), s.end());
    return s;
}

// Space-Optimized, however can't find subsequence
int lcs(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        swap(prev, curr);
    }
    return prev[m];
}
```

#### Shortest Common Supersequence
```cpp
string shortestCommonSupersequence(string &s1, string &s2) {
    // Step 1: Build LCS dp table

    // Step 2: Reconstruct SCS using dp table
    int i = n, j = m;
    string res;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            res += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            res += s1[i-1];
            i--;
        }
        else {
            res += s2[j-1];
            j--;
        }
    }
    while(i > 0) res += s1[i-1], i--;
    while(j > 0) res += s2[--j];

    reverse(res.begin(), res.end());
    return res;
}
```

## 5. String DP

### Edit Distance
- Memoization   
```cpp
int rec(vector<vector<int>> &dp, string &s1, string &s2, int n, int m){
    if(n == 0) return m;
    if(m == 0) return n;
    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n - 1] == s2[m - 1]){
        return dp[n][m] = rec(dp, s1, s2, n - 1, m - 1);
    }
    return dp[n][m] = 1 + min({rec(dp, s1, s2, n, m - 1), 
                               rec(dp, s1, s2, n - 1, m), 
                               rec(dp, s1, s2, n - 1, m - 1)});
}

int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return rec(dp, word1, word2, n, m);
}
```

- Tabulation
```cpp
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}
```

## 6. Bitmask DP


## 7. Digit DP

```cpp
int dp[20][200][2];     // dp[pos][sum][tight]

// pos  = current index in string
// sum  = any property we want to track (e.g. sum of digits)
// tight= 1 if prefix matches limit, else 0

int rec(string &s, int n, int sum, bool tight) {
    if(prune_case) return 0;
    if(n == 0) {
        return base_case ? 1 : 0;
    }
    if(dp[n][sum][tight] != -1) return dp[n][sum][tight];

    int limit = tight ? (s[s.size() - n] - '0') : 9;
    int ans = 0;
    for(int dig = 0; dig <= limit; dig++) {
        ans += rec(s, n - 1, sum + dig, tight && (dig == limit));
    }
    return dp[n][sum][tight] = ans;
}

int solve(string s) {
    memset(dp, -1, sizeof(dp));
    return rec(s, s.size(), 0, true);
}

string decrement(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';
        i--;
    }
    if (i >= 0) s[i]--;
    int idx = 0;
    while (idx + 1 < s.size() && s[idx] == '0') idx++;
    return s.substr(idx);
}

int ans(string L, string R) {
    int ans = solve(r);
    if (L == 0) return ans; 
    l = decrement(l);
    ans -= solve(l, k);
    return ans;
}
```