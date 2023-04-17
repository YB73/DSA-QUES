class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int i,j,m=grid.size(),n=grid[0].size(),k;
        vector<int> ans(n,0);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                k = to_string(grid[i][j]).length();
                ans[j] = max(ans[j],k);
            }
        }
        return ans;
        
        
    }
};