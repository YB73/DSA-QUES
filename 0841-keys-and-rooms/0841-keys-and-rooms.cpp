class Solution {
public:
    void dfs(int node, unordered_map<int, bool> &mp, vector<vector<int>> &adj){
        mp[node]=true;
        for(auto i:adj[node]){
            if(!mp[i]){
                dfs(i, mp, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_map<int,bool> mp;
        for(int i=0;i<n;i++){
            mp[i]=false;
        }
        dfs(0, mp, rooms);
        for(int i=0; i<mp.size(); i++){
            if(!mp[i]){
                return false;
            }
        }
        return true;
    }
};