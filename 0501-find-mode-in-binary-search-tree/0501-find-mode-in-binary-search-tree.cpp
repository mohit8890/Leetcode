/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>map;

    void solve(TreeNode* root){
        if(!root)
        return;

        map[root->val]++;
        if(root->left)
        solve(root->left);
        if(root->right)
        solve(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        solve(root);
        int m=INT_MIN;
        int mf=0;

        for(auto x:map){
            if(x.second>=mf){
                m=x.first;
                mf=x.second;
            }
        }
        vector<int>v;

        for(auto x:map){
            if(x.second ==mf){
                v.push_back(x.first);

            }
        }
        return v;

        
    }
};