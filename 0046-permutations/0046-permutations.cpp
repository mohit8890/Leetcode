class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
    }
    void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};