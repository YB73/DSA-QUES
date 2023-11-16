class Solution {
public:
    long long getWays(int candies, int limit) {
    long long minn = max(0, candies-limit);
    long long maxxx = min(candies, limit);
    return maxxx -minn+1 > 0 ? maxxx -minn+1 : 0;
}
    long long distributeCandies(int n, int limit) {
   long long ways = 0;
    for(int candies=0; candies<=min(n, limit); candies++) {
        ways += getWays(n-candies, limit);
    }
    return ways;
    }
};