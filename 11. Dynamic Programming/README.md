# Table of Contents
**[Dynamic Programming](#dynamic-programming)**
- [Basic Theory](#basic-theory)
- [Recursive vs Iterative](#recursive-vs-iterative)

**[Resources](#resources)**

# Dynamic Programming

### Basic Theory:

- States : Represents the value(s) that the discarded information was compressed to, and also represents the subproblems we solve to build up to the main problem.
    - In Knapsack problem, our state can be defined by two parameters index and weight i.e dp[index][weight].
<br>

- Transitions : Represents the way that states interact with each other
    - In the grid example, the iterative method’s transitions are pushing the answers to the downward and rightward cells: dp(r + 1, c) += dp(r, c); dp(r, c + 1) += dp(r, c)
    - The recursive transitions are given by the formula: dp(r, c) = dp(r - 1, c) + dp(r, c - 1)
<br>

- Base cases : Easiest states which we already know the answer to. dp[0] = 0, dp[0][0] = 1, etc.
<br>

- Push vs Pull DP : 
    - Pull DP "pulls" answer from previous DP values (recursive solution) ex. dp(r,c) = dp(r-1,c) + dp(r,c-1)
    - Recursive can only be pull dp.
    - Push DP "pushes" answer to future DP values (iterative solution) dp(r+1,c) += dp(r,c); dp(r,c+1) += dp(r,c)

### Recursive vs Iterative
- Top-down (memoization)
    -  Start from highest level of problem
    - Check if we have solved current sub-problem
    - Computes only those solutions which are needed
- Bottom-Up (Tabulation)
    - Start at the bottom and work our way to the top 
    - Calculates all solutions in the range

Nth fibonacci number
- Recursive
```c++
int fibo(int n){
    if(n <= 1){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}
```
- Iterative
```c++
int fibo(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

## Resources
[AtCoder DP Contest](https://atcoder.jp/contests/dp)

[DP tutorial and problem list](https://codeforces.com/blog/entry/67679)

[Non-trivial DP tricks](https://codeforces.com/blog/entry/47764)

[Bigass cf blog](https://codeforces.com/blog/entry/43256)

[CSES DP tutorials](https://codeforces.com/blog/entry/70018)
