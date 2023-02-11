class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &re : redEdges){
            adj[re[0]].push_back({re[1], 0});
            
        }
                for(auto &be : blueEdges){
            adj[be[0]].push_back({be[1], 1});
            
        }
        vector<int> answer(n, -1);  // Initialize the answer array with -1 for all nodes
        vector<vector<bool>> visit(n, vector<bool>(2));  // Keep track of which nodes have been visited with each color
        queue<vector<int>> q; 
        
        q.push({0, 0, -1});
        visit[0][1] = visit[0][0] = true;
        answer[0] = 0;
        
        while(!q.empty()){
            auto element = q.front();
            int node = element[0], steps = element[1], prevC = element[2];
            q.pop();
            for(auto &[n, c] : adj[node]){
                if(!visit[n][c] && c != prevC){
                    visit[n][c] = true;
                    q.push({n, 1+steps, c});
                    if(answer[n] == -1) answer[n] = 1 + steps;
                }
            }
        }
        return answer;
        
    }
};