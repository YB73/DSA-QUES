class Solution {
public:
   bool giveAns(int currCandy, vector<int>& candies, long long k) {
       
		
        for (auto& c : candies)   k -= (c/currCandy);
        return k <= 0;
    }
    
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        int start(1), end(INT_MIN);
        for (auto& candy : candies) end = max(end, candy);
        
        while (start <= end) {
            int currCandy = start+(end-start)/2;
	
            if (giveAns(currCandy, candies, k))    start = currCandy+1;
            else    end = currCandy-1;
        }
        return end;  
    }
};