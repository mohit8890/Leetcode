class Solution {
public:
  int solve(vector<int>& cost, vector<int>& time, int idx, int wall, vector<vector<int>>& dp) {
    // Agar wall nahi hai, toh cost bhi nahi hai.
    if (wall <= 0) {
      return 0;
    }

    // Agar color nahi hai, toh wall nahi paint kar sakte, toh bohot badi cost return karenge.
    if (idx >= cost.size()) {
      return 1000000000;
    }

    // Agar is index aur is wall ke liye cost calculate kar li hai, toh directly return kar denge.
    if (dp[idx][wall] != -1) {
      return dp[idx][wall];
    }

    // Ab, do cases consider karenge:
    //
    // 1. Is color ko use nahi karenge.
    // 2. Is color ko use karenge aur next wall ko paint karne ke liye aage badhenge.

    // Pehle case ke liye, next color pe consider karenge aur same wall ke liye cost calculate karenge.
    int not_take = solve(cost, time, idx + 1, wall, dp);

    // Dusre case ke liye, is color ki cost add karenge aur next wall ko paint karne ke liye aage badhenge.
    int take = cost[idx] + solve(cost, time, idx + 1, wall - time[idx] - 1, dp);

    // Finally, in do cases mein se minimum cost return karenge.
    dp[idx][wall] = min(take, not_take);

    return dp[idx][wall];
  }

  int paintWalls(vector<int>& cost, vector<int>& time) {
    // Ek dynamic programming table banayenge jo humein pehle calculate ki hui costs store karne ki permission dega.
    vector<vector<int>> dp(cost.size() + 1, vector<int>(time.size() + 1, -1));

    // solve() function ko call karenge aur first wall ke liye cost return karenge.
    return solve(cost, time, 0, time.size(), dp);
  }
};