class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
               int peak_index = 0;
    int peak_element = arr[0];
    int mid = arr.size()/2;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > peak_element){
            peak_element = arr[i];
            peak_index = i;
        }

    }
    return peak_index;
    }
};