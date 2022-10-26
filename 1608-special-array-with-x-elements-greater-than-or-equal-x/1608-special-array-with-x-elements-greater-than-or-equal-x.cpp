class Solution {
public:
    int specialArray(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int i=nums.size();
		
        while(i>0){
            int start=0,end=nums.size()-1;
            int count=0;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(nums[mid]>=i){
                   count+=end-mid+1;    // no. of element greater than nums[mid] 
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            if(count==i){
                return i;
            }
            i--; 
        }
        return -1;
    }
};