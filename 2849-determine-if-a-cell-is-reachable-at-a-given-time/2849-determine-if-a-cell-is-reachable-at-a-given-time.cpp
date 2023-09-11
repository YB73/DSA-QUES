class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
         int diffX = abs(sx - fx);
        int diffY = abs(sy - fy);

        if(diffX==0 && diffY==0){
            return t != 1;
        }
        if(diffX<=t && diffY<=t){
            return true;
        }
        
        return false;
    }
};