class Solution {
public:
    vector<vector<int>> dp;
    int unfairness(vector<int>& cookies, int n, int k, int bagMask) {
        if (dp[k][bagMask] != -1) return dp[k][bagMask];
        
        auto sum_cookies=[&](int Mask)-> int{
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (Mask & (1 << i))
                    sum += cookies[i];
            }
            return sum;
        };

        if (k == 1) 
            return dp[k][bagMask] = sum_cookies(bagMask);

        int ans = INT_MAX;
        for (int Mask = bagMask; Mask > 0; Mask = (Mask - 1) & bagMask) {
            int sum1 = sum_cookies(Mask);
            int sum2 = unfairness(cookies, n, k - 1, bagMask ^ Mask);
            ans = min(ans, max(sum1, sum2));
        }

        return dp[k][bagMask] = ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        dp.assign(k + 1, vector<int>(1 << n, -1));
        return unfairness(cookies, n, k, (1 << n) - 1);
    }
};