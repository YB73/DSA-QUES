class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
            int n = a.size();
        int x = (n)/4;

        int cnt = 0;
        int cur = a[0];
        for(int i : a){
            if(i > cur){
                if(cnt > x)return cur;
                cnt = 1;
                cur = i;
            }
            else cnt++;
        }
        if(cnt > x)return cur;
        return a[0];
    }
};