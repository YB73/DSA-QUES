class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int i = 0, j = 0, k = 0;
  int m = nums1.size(), n = nums2.size();
    // Traverse both array
    vector<int> nums3(m+n);
    while (i<m && j <n)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (nums1[i] < nums2[j])
            nums3[k++] = nums1[i++];
        else
            nums3[k++] = nums2[j++];
    }
  
    // Store remaining elements of first array
    while (i < m)
        nums3[k++] = nums1[i++];
  
    // Store remaining elements of second array
    while (j < n)
        nums3[k++] = nums2[j++];



       if(nums3.size()%2 == 0)
        return double((nums3[nums3.size()/2 - 1] + nums3[nums3.size()/2])/2.0);
       
       else
        return double(nums3[nums3.size()/2.0]);
    }
};