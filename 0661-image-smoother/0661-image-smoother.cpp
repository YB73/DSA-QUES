class Solution {
public:
    int get_avg(int i, int j, const vector<vector<int>> &img) {
        int sum = 0;
        int count = 0;

        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                int r_new = i + x;
                int c_new = j + y;
                if (r_new < 0 || r_new >= img.size() || c_new < 0 || c_new >= img[0].size()) {
                    continue;
                }
                sum += img[r_new][c_new];
                count++;
            }
            
        }
        return floor(sum / count);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = get_avg(i, j, img);
            }
        }

        return result;
    }
};