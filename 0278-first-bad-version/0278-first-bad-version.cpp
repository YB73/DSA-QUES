// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1){
            return 1;
        }
        long long bad;
        long long l = 1;
        long long r = n;
        long long ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(isBadVersion(mid)){
                r = mid-1;
            }
                       
           else l = mid+1;
            
            if(isBadVersion(mid) && !(isBadVersion(mid-1))){
                ans=mid;
            }
            
        }
        return ans;
        
    }
};