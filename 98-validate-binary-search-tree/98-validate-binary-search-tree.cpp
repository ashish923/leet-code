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
    bool isValidBST(TreeNode* root) {
        
        
      vector<int> vc;
        solve(root,vc);
        
        for(int i=0; i<vc.size()-1; i++){
            if(vc[i]>= vc[i+1])
                return false;
        }
        
        return true;
    }
    
    void solve(TreeNode* root,vector<int> &vc){
        if(!root)
            return;
        solve(root->left,vc);
        vc.push_back(root->val);
        solve(root->right,vc);
    }
};