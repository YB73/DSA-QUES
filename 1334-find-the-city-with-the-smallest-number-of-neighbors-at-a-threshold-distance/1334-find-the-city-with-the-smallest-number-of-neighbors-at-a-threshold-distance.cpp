class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(auto it : edges){
            int to = it[1];
            int from = it[0];
            int weight = it[2];
            dist[to][from] = weight;
            dist[from][to] = weight;
        }
        for(int thr = 0; thr < n; thr++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][j] > dist[i][thr] + dist[thr][j]){
                        dist[i][j] = dist[i][thr] + dist[thr][j];
                    }
                }
            }
        }
             int mincnt = n, city = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(mincnt >= cnt){
                mincnt = cnt;
                city = i;
            }
        }
        return city;
        
        
    }
};