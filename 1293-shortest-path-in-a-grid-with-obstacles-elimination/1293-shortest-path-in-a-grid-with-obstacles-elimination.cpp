class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> g = grid;
         int m = g.size(), n = g[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, k, 0, 0});

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> dist(m, vector<int>(n, -1));

    while (!pq.empty()) {
        int steps = pq.top()[0], remainingCanBeBroken = pq.top()[1];
        int x = pq.top()[2], y = pq.top()[3];
        pq.pop();

        if (x == m - 1 && y == n - 1) return steps;

        for (auto& dir : dirs) {
            int dx = x + dir[0], dy = y + dir[1];
            if (min(dx, dy) < 0 || dx == m || dy == n || g[dx][dy] < 0) continue;

            int rem = remainingCanBeBroken - (g[dx][dy] == 1);
			
			//if more K yet to can be broken, go for it.
            if (rem >= 0 && rem > dist[dx][dy]) {
                pq.push({steps + 1, rem, dx, dy});
                dist[dx][dy] = rem;
            }
        }
    }
    return -1;
    }
};