class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int x;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second > 1){
                x = it->first;
            }
        }
        return x;
    }
};