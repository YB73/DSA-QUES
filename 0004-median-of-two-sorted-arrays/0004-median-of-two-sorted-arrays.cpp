class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>newNums;
        for(int i=0;i<n1;i++)
            newNums.push_back(nums1[i]);
        for(int i=0;i<n2;i++)
            newNums.push_back(nums2[i]);
        sort(newNums.begin(),newNums.end());
        int n = newNums.size();
        return n%2?newNums[n/2]:(newNums[n/2-1]+newNums[n/2])/2.0;
    }
};