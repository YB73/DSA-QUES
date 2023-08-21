class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i=0;i<n;i++){
            int ep = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                int length = wall[i][j];
                ep = ep + length;
                mp[ep]++;
                mx = max(mx, mp[ep]);
            }
        }
        return n - mx;
    }
};