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
    int d=0;
    int deepestLeavesSum(TreeNode* root) {
        
        int sum = 0,s =0;
        
        int h = maxDepth(root);
        d = h;
        int k=0;
        solve(root,s,sum);
        return sum;
        
    }
    
   void solve(TreeNode* root,int s, int &sum){
       if(root==NULL)
           return;
       
       if(root->left == NULL && root->right == NULL && s==d-1){
           sum += root->val;
           return;
       }
       
       solve(root->left,s+1,sum);
       solve(root->right,s+1,sum);
    }
    
    int maxDepth(TreeNode* root) {
        
        
        if(root==NULL)
            return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh,rh);
    }
};