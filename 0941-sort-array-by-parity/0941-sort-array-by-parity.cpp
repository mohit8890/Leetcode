class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int first = 0;
        int last = n - 1;

        while (first < last) {
            while (first < last && nums[first] % 2 == 0) {
                first++;
            }

            while (first < last && nums[last] % 2 == 1) {
                last--;
            }

            if (first < last) {
                swap(nums[first], nums[last]);
            }
        }

        return nums;
    }
};