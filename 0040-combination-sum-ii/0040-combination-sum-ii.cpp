class Solution {
private:
    void solver(int i, int target, vector<int>& candi, vector<int>& res, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        if(i == candi.size()){
            return;
        }

        if(candi[i] <= target){
            res.push_back(candi[i]);
            solver(i+1,target-candi[i],candi,res,ans);
            res.pop_back();
        }

        while(i+1<candi.size() && candi[i] == candi[i+1]){
            i++;
        }
        // 1,1,1,2,2,3,4,5,6
        solver(i+1,target,candi,res,ans);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        solver(0,target,candidates,res,ans);
        return ans;
    }
};