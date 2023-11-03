class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        vector<int> subarray;
        string tmp;
        for(int i =0;i<nums.size();i++)
        {
            while((i+1)<nums.size() && nums[i]==nums[i+1]-1)
            {
                subarray.push_back(nums[i]);
                i++;

            }
            subarray.push_back(nums[i]);
            if(subarray.size()==1)
                tmp =to_string(subarray[0]);
            else
                tmp = to_string(subarray[0])+"->" + to_string(subarray[subarray.size()-1]);
            result.push_back(tmp);
            subarray.clear();

        }
        return result;

    }
};