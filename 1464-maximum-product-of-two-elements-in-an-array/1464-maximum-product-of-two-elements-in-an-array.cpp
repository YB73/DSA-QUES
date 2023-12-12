class Solution {
public:
    int maxProduct(vector<int>& a) {
              int mx1,mx2;
        mx1=mx2=INT_MIN;
        for(int i=0;i<a.size();i++){
            if(a[i]>mx1){
                mx2 = mx1;
                mx1 = a[i];
            }
            else if(a[i]>mx2)
                mx2 = a[i];
        }
        return (mx1-1) * (mx2-1);
    }
};