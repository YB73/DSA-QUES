class Solution {
public:
     int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Preprocess the matrix to calculate the height of consecutive 1's ending at each position
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = (i == 0) ? 1 : dp[i - 1][j] + 1;
                }
            }
        }

        int ans = 0;
        // Sort and calculate the area for each column
        for (int i = 0; i < m; i++) {
            sort(dp[i].begin(), dp[i].end(), greater<int>());
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j] * (j + 1));
            }
        }

        return ans;
    }
};