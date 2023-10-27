class Solution {
public:
    void subsequence(int ind,int tar,vector<int>& cand,vector<int>& subseq,vector<vector<int>>&  ans)
    {
        if(ind >= cand.size())
        {
            if(tar == 0)
            {
                ans.push_back(subseq);
            }
            return;
        }
        
        subseq.push_back(cand[ind]);
        if(tar-cand[ind] >= 0)
        {
            subsequence(ind,tar-cand[ind],cand,subseq,ans);// pick the cand[ind] to make target
        }
        
        subseq.pop_back();
        subsequence(ind+1,tar,cand,subseq,ans);// not pick the cand[ind]
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        subsequence(0,target,candidates,subseq,ans);
        return ans;
    }
};