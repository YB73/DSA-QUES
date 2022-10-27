class Solution {
public:
    int solve(int right, int down, vector<vector<int>> &mat1, vector<vector<int>> &mat2)
    {
        int c = 0, n=mat1.size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i+down>=0 && i+down<n && j+right>=0 && j+right<n)
                {
                    if(mat1[i][j] == 1 && mat2[i+down][j+right] == 1)
                    {
                        c++;
                    }
                }
            }
        }
        
        return c;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int c = 0, n=img1.size();
        
        for(int i=-n+1; i<n; i++)
        {
            for(int j=-n+1; j<n; j++)
            {
                c = max(c, solve(i, j, img1, img2));
            }
        }
        
        return c;
        
    }
    
};