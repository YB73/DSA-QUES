class Solution {
public:
    int dp[71][71][71];
    vector<pair<int,int>>v={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    int helper(int i1,int j1,int j2,vector<vector<int>>&grid){
        if(dp[i1][j1][j2]!=-1)return dp[i1][j1][j2];
        int temp=0;
        if((j1==j2)){
            temp+=grid[i1][j1];
        }
        else temp+=grid[i1][j1]+grid[i1][j2];
        int ans=temp;
        for(int i=0;i<v.size();i++){
            if((j1+v[i].first>=0)&&(j1+v[i].first<grid[0].size())&&(j2+v[i].second>=0)&&(j2+v[i].second<grid[0].size())&&(i1+1<grid.size())){
                ans=max(ans,temp+helper(i1+1,j1+v[i].first,j2+v[i].second,grid));
            }
        }
        return dp[i1][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
    memset(dp,-1,sizeof(dp));
    return helper(0,0,grid[0].size()-1,grid);    
    }
};