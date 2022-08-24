class Solution {
public:
    vector<int> ans;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     set<int> s;
        for(int i=0; i<nums1.size(); i++){
            s.insert(nums1[i]);
        }
        for(auto it : nums2){
            if(s.erase(it)){
                ans.push_back(it);
            }
            
        }
        return ans;
    }
    
};