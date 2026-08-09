class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        for(int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        // Fill DP
        for(int i = 1; i < n; i++) {
            // Find max and second max in previous row
            int rowMax = -1, rowSecondMax = -1, rowMaxCol = -1;
            for(int j = 0; j < n; j++) {
                if(dp[i-1][j] > rowMax) {
                    rowSecondMax = rowMax;
                    rowMax = dp[i-1][j];
                    rowMaxCol = j;
                } else if(dp[i-1][j] > rowSecondMax) {
                    rowSecondMax = dp[i-1][j];
                }
            }

            // Transition
            for(int j = 0; j < n; j++) {
                if(j == rowMaxCol) {
                    dp[i][j] = mat[i][j] + rowSecondMax;
                } else {
                    dp[i][j] = mat[i][j] + rowMax;
                }
            }
        }

        // Final answer
        int ans = 0;
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[n-1][j]);
        }
        return ans;
    }
};
