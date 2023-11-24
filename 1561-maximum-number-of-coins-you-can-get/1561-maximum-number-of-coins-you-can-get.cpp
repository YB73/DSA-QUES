class Solution {
public:
    int maxCoins(vector<int>& piles) {
          int n=piles.size();
        int t=n/3, res=0;
        sort(piles.begin(), piles.end(), greater<int>());
        for(int i=1;i<n-t;i+=2){
            res+=piles[i];
        }
        return res;
    }
};