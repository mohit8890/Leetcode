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
    bool symmetric(TreeNode *lst,TreeNode *rst) {
        if(lst==NULL && rst==NULL)return true;
        if(lst==NULL || rst ==NULL) return false;
        if(lst->val!=rst->val ) return false;
        return symmetric(lst->left,rst->right)&&symmetric(lst->right,rst->left);

        
        
    }
    bool isSymmetric(TreeNode* root){
        if(!root || root->right==NULL && root->left==NULL )return true;
        return symmetric(root->left,root->right);
    }
};