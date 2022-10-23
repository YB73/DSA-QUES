class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        vector<int> res;
        int y = 1;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            
        }
        for(int i=1; i<=nums.size(); i++){
            if(m[i] == 2){
                res.push_back(i);
                
            }
            else{
                if(m[i] == 0)
                y = i;
            }
        }
        res.push_back(y);
        return res;
        
    }
};