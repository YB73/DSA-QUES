class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		//Creating auxiliary matrix of size nXm... n=matrix[0].size and m=matrix.size()
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
        
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                res[j][i] = matrix[i][j];
            }
        }
        
        return res;
    }
};