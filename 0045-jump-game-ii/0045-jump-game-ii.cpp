class Solution {
public:
    vector<int>dp;

    int util(vector<int>& nums, int idx){
        if(idx>=nums.size()-1){
            return 0;

        }
        if(dp[idx]!=-1)return dp[idx];

        if(nums[idx]==0)return (int)1e5+5;

        int ans= 1e5+5;
        for(int i= nums[idx]; i>=1; i--){
            ans= min(ans, util(nums, idx+i)+1);
        }
        return dp[idx]= ans;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);

        return util(nums, 0);

    }
};