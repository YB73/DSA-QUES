class Solution {
public:
   int n, ans = INT_MAX;
vector<int> graph[10005];

int bfs(int src) {
    queue<int> q;
    vector<int> dist(10005, -1);
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            } else if (dist[v] >= dist[u]) {
                ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
    return ans;


   
}
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for (auto it:edges)
        {
        int u=it[0], v=it[1];
        // cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        }
        
        for (int i = 0; i < n; i++) {
            bfs(i);
        }
        if (ans == INT_MAX) 
            return -1;
        else
            return ans;
        
    }
};