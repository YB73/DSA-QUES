class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), d[5] = {-1, 0, 1, 0, -1}, MOD = 1'000'000'007; 
        vector<vector<int>> indeg(m, vector<int>(n)); 
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                for (int k = 0; k < 4; ++k) {
                    int ii = i+d[k], jj = j+d[k+1]; 
                    if (0 <= ii && ii < m && 0 <= jj && jj < n && grid[i][j] < grid[ii][jj]) 
                        ++indeg[i][j]; 
                }
        
        queue<pair<int, int>> q; 
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (indeg[i][j] == 0) q.emplace(i, j); 
        
        long long ans = 0; 
        vector<vector<long long>> dp(m, vector<long long>(n, 1)); 
        while (q.size()) {
            auto [i, j] = q.front(); q.pop(); 
            ans = (ans + dp[i][j]) % MOD; 
            for (int k = 0; k < 4; ++k) {
                int ii = i+d[k], jj = j+d[k+1]; 
                if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                    if (grid[i][j] > grid[ii][jj]) {
                        dp[ii][jj] = (dp[i][j] + dp[ii][jj]) % MOD; 
                        if (--indeg[ii][jj] == 0) q.emplace(ii, jj); 
                    }
                }
            }
        }
        return ans; 
    }
    
};