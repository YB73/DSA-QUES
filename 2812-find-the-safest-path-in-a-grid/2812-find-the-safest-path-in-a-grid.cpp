#define PI pair<int,int>
#define PIP pair<int,pair<int,int>>


vector<vector<int> > dirs{{0,-1},{0,1},{-1,0},{1,0}};
class Solution {
    bool inside(int r,int c,int n){
        if(r<0||c<0)return false;
        if(r<n&&c<n)return true;
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(),r,c,r1,c1;
        vector<vector<int> > max_dist(n,vector<int> (n,INT_MAX));
        queue<PI> q;

        // Initilizing minimum manhattan distance as zero, where thief found
        for(r=0;r<n;r++){
            for(c=0;c<n;c++){
                if(grid[r][c]){
                    q.push({r,c});
                    max_dist[r][c]=0;
                }
            }
        }
        
        // Finding minimum manhattan distance from thief for each cell 
        while(!q.empty()){
            r=q.front().first;
            c=q.front().second;
            q.pop();
            for(auto &dir:dirs){
                r1=r+dir[0];
                c1=c+dir[1];
                if(inside(r1,c1,n) && max_dist[r1][c1]>max_dist[r][c]+1){
                    max_dist[r1][c1]=max_dist[r][c]+1;
                    q.push({r1,c1});
                }
            }
        }
        
        priority_queue<PIP> pq;
        vector<vector<int> > dp(n,vector<int> (n,0));
        
        dp[0][0]=max_dist[0][0];
        pq.push({dp[0][0],PI{0,0}});
        PIP u,v;
        
        while(!pq.empty()){
            u=pq.top();
            pq.pop();
            r=u.second.first;
            c=u.second.second;
            if(r==n-1&&c==n-1)return dp[r][c];
            
            for(auto &dir:dirs){
                r1=r+dir[0];
                c1=c+dir[1];
                if(inside(r1,c1,n) && dp[r1][c1]< min(dp[r][c],max_dist[r1][c1])){
                    dp[r1][c1]=min(dp[r][c],max_dist[r1][c1]);
                    pq.push({dp[r1][c1],PI{r1,c1}});
                }
            }
        }
        return dp[n-1][n-1];
    }
};