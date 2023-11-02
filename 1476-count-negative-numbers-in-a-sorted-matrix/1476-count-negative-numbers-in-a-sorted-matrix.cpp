class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size() -1,curr_row=0, ans=0;
        while(cols >=0  && curr_row <rows)
        {
            if(grid[curr_row][cols]>=0)
                curr_row++;
            else
                ans+=(rows-curr_row),cols--;
        }
        return ans;
        
    }
};