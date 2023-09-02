class Solution {
public:
    
    // Graph DFS to find the connected components
    void dfs(int pos, vector<vector<int>>& adj, vector<int> &vis, vector<int> &group, int top){
        group[pos] = top;
        vis[pos] = 1;
        for(int i = 0 ; i < adj[pos].size() ; i++){
            int cur = adj[pos][i];
            if(vis[cur] == 0){
                dfs(cur, adj, vis, group, top);
            }
        }
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& as) {
        int n = source.size();
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < as.size() ; i++){
            adj[as[i][0]].push_back(as[i][1]);
            adj[as[i][1]].push_back(as[i][0]);
        }
        vector<int> vis(n , 0);
        vector<int> group(n);
        for(int i = 0 ; i < n ; i++){
            group[i] = i;
        }

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, group , i);
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i < n ; i++){
            mp[group[i]].push_back(i);
        }
        
        int ans = 0;
        for(auto i : mp){
            vector<int> pos = i.second;
            unordered_map<int, int> check;
            for(int j = 0 ; j < pos.size() ; j++){
                check[source[pos[j]]]++;
            }
            
            for(int j = 0 ; j < pos.size() ; j++){
                if(check[target[pos[j]]] > 0){
                    check[target[pos[j]]]--;
                }else{
                    ans++;
                }
            }
            
        }
        return ans;
    }
};