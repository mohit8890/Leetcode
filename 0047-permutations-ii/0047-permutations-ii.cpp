class Solution {
public:
    void f(set<vector<int>>&res,vector<int>&temp,vector<int>& nums,vector<int>& vis){
        if(nums.size()==temp.size()){
            res.insert(temp);
            return;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(nums[i]);
                f(res,temp,nums,vis);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>res;
        vector<int>temp;
        vector<int>vis(nums.size(),0);
        f(res,temp,nums,vis);
        vector<vector<int>>ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};