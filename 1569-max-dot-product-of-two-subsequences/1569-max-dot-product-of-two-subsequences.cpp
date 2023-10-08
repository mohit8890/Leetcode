class Solution {
public:
    int dp[501][501];
    int helper(int i, int j, vector<int>& nums1, vector<int>& nums2, int n, int m,bool dot){
        if(i == nums1.size() || j == nums2.size()) {
            if(dot) return 0;
            return INT_MIN;
        }
        int ans = INT_MIN;
        if(dp[i][j]!=0) return dp[i][j];
        
        ans = nums1[i]*nums2[j] + helper(i+1,j+1,nums1, nums2, n, m, true);
        ans = max(ans, helper(i+1,j,nums1,nums2,n,m,dot));
        ans = max(ans, helper(i,j+1,nums1,nums2,n,m,dot));
        ans = max(ans, helper(i+1,j+1,nums1,nums2,n,m,dot));
        return dp[i][j] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        bool dot=false;
        memset(dp,0,sizeof(dp));
        return helper(0,0,nums1, nums2, n, m,dot);

    }
};