class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if(intervals.size() <= 1)
            return intervals;

        // Sort the intervals based on the first element of each sub-interval
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
            {
                return a[0] < b[0];
            }
        );

        vector<vector<int>> res;
        int n = intervals.size();

        for(int i=0; i<n; i++)
        {
            if(res.size() && intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};