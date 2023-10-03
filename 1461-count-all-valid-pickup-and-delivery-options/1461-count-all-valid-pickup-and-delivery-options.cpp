class Solution {
public:
    int countOrders(int n) {
        vector<long> dp(n, -1);
        int mod = 1e9 + 7;

        dp[0] = 1;
        for(long i = 1; i<n; i++){
            dp[i] = ((i+1)*dp[i-1]*(2*i+1))%mod;
        }
        return dp[n-1];
    }
};