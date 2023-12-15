class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int special = 0;

        unordered_map<int,int> vis_rows;
        unordered_map<int,int> vis_cols;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j]==1)
                {
                    vis_rows[i]++;
                    vis_cols[j]++;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (vis_rows.find(i)!=vis_rows.end() && vis_cols.find(j)!=vis_cols.end())
                {
                    if (vis_rows[i] == 1 and vis_cols[j]==1)
                    {
                        if (mat[i][j]==1)
                            special++;
                    }
                }
            }
        }

        return special;
        
    }
};