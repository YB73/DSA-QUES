class Solution {
public:
     int solve(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;
        int count = 0;
        vector<bool> visited(n,0);
        pq.push({0,0});
        while(!pq.empty()){
            auto [w, i] = pq.top();
            pq.pop();
            if (visited[i]) continue;
            visited[i] = 1;
            ans+=w;
            count++;
            if(count == n) return ans;
            for(int j=0; j<n; j++){
                if(visited[j]) continue;
                int &&wt = solve(points[i], points[j]);
                pq.push({wt,j});
             }
        }
        return -1;
        
        
    }
};