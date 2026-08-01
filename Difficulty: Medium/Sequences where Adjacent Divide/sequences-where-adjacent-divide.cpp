class Solution {
  public:
    int count(int n, int m) {
        // adjacency list: for each x, store all y such that x divides y or y divides x
        vector<vector<int>> adj(m+1);
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= m; y++) {
                if (x % y == 0 || y % x == 0) {
                    adj[x].push_back(y);
                }
            }
        }
        
        // dp[len][val] = number of arrays of length len ending with val
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        
        // base case: arrays of length 1
        for (int val = 1; val <= m; val++) {
            dp[1][val] = 1;
        }
        
        // fill dp for lengths 2..n
        for (int len = 2; len <= n; len++) {
            for (int val = 1; val <= m; val++) {
                for (int prev : adj[val]) {
                    dp[len][val] += dp[len-1][prev];
                }
            }
        }
        
        // answer = sum of all arrays of length n
        long long ans = 0;
        for (int val = 1; val <= m; val++) {
            ans += dp[n][val];
        }
        return (int)ans;
    }
};
