class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double ans =0;
        int n = salary.size();
        for(int i=1; i<n-1;i++){
            ans +=salary[i];
        }
        ans = ans/(n-2);
        return ans;
    }
};