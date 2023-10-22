class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int left =k , right =k;
        int min_val = nums[k];
        int res = min_val;
        while(left >0|| right<nums.size()-1){
            if(left==0||((right<nums.size()-1)&& nums[right+1]> nums[left-1])){
                right++;
            }
            else left--;
            min_val = min(min_val,min(nums[left],nums[right]));
            res = max(res,min_val*(right - left +1));

        }
        return res;
        
    }
};