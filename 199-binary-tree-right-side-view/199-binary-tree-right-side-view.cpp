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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
       rightview(root,res,0);
        return res;
    }
    
    void rightview(TreeNode* root,vector<int> &res,int level){
        
        if(root == NULL)
            return ;
        if(res.size() == level) res.push_back(root->val);
        
        rightview(root->right,res,level+1);
        rightview(root->left,res,level+1);
    }
};