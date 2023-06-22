class Solution {
public:
    int dp[105][105];
    int rec(int i,int j, vector<vector<int>>&a){
        if(i==a.size()) return 0;
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int op1 = INT_MAX , op2= INT_MAX , op3 = INT_MAX;
        if(j-1>=0){
            op1 = min(op1 , a[i][j] + rec(i+1,j-1,a));
        }
        
        if(j+1<a[0].size()){
            op2 = min(op2, a[i][j] + rec(i+1,j+1,a));
        }
        op3 = min(op3, a[i][j] + rec(i+1,j,a));
        return dp[i][j] = min({op1, op2, op3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()+1;i++){
            for(int j=0;j<=matrix[0].size();j++){
                dp[i][j] = INT_MAX;
            }
        }
        int ans = INT_MAX;
        for(int i=1;i<=18;i++){
            cout<<dp[i][0]<<endl;
        }
        for(int j=0;j<matrix[0].size();j++){
            ans = min(ans , rec(0,j,matrix));
        }
        return ans;
    }
};