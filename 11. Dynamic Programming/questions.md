https://codeforces.com/contest/189/submission/253315832

#### [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)
```c++
// Iterative Push DP
int main() {
	int N;
	cin >> N;
	vector< int > height(N);
	for (int i = 0; i < N; i++) { cin >> height[i]; }
	vector<int> dp(N, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(height[i] - height[i + 1]));
		if (i + 2 < N) {
			dp[i + 2] = min(dp[i + 2], dp[i] + abs(height[i] - height[i + 2]));
		}
	}
	cout << dp[N - 1] << endl;
}

// Iterative Pull DP
int main() {
	int N;
	cin >> N;
	vector<int> height(N);
	for (int i = 0; i < N; i++) { cin >> height[i]; }
	vector<int> dp(N, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < N; i++) {
		if (i  >= 1) {
			dp[i] = min(dp[i], dp[i - 1] + abs(height[i] - height[i - 1]));
		}
		// jump one stone
		if (i  >= 2) {
			dp[i] = min(dp[i], dp[i - 2] + abs(height[i] - height[i - 2]));
		}
	}
	cout << dp[N - 1] << endl;
}
```