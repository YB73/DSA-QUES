class Solution {
public:
    bool helper(vector<int>&weights, int mid, int days){
        int sum=0;
        int count=1;
        int n = weights.size();
        for(int i=0; i<n; i++){
            sum+=weights[i];
            if(sum > mid){
                count++;
                sum=weights[i];
            }
            
        }
        if(count<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxcap=0;
        int res;
        int n = weights.size();
        for(int i=0; i<n; i++){
            maxcap+=weights[i];
        }
        int low=*max_element(weights.begin(), weights.end()),high=maxcap;
        while(low<=high){
            int mid = (low + high)/2;
            if(helper(weights,mid,days)){
                res = mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};