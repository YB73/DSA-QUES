class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1=0,max2=0,min1=100001,min2=100001;
        for(auto &it:nums){
            if(it>max1){
                max2=max1;
                max1=it;
            }
            else if(max2<it){
                max2=it;
            }
            if(it<min1){
                min2=min1;
                min1=it;
            }
            else if(min2>it){
                min2=it;
            }
        }
        return (max1*max2)-(min1*min2);
    }
};