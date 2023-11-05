class Solution {
public:
    int helper(vector<vector<int>>& triangle,int i,int j,int m,int n,vector<vector<int>>&dp){

        if(i == m-1 || j == n-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int path1 = triangle[i][j] + helper(triangle,i+1,j,m,n,dp);
        int path2 = triangle[i][j] + helper(triangle,i+1,j+1,m,n,dp);

        return dp[i][j] = min(path1,path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return helper(triangle,0,0,m,n,dp); 
    }
};