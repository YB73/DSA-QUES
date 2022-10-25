class Solution {
public:
    int mySqrt(int x) {
         int l = 1;
    int r = x/2;
    int ans;
    long temp;
    if(x<=1){
        return x;
    }

    while(l<=r){
        int mid = (l+r)/2;
        temp = (long)mid * (long)mid;
        if(temp == x){
            return mid;
        }
        else if(temp < x){
            ans = mid, l = mid+1;
        }
        else{
            r = mid-1;
        }

    }
    return ans;
    }
};