class Solution {
public:
    int countOrders(int n) {
        long long orders=1;
        for(int i=2;i<=n;i++){
            orders=(orders*(2*i-1)*i)%1000000007;
        }
        return (int) orders;
    }
};