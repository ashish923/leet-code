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
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        
        int h = 0; 
      solve(root,k,h);
        return ans;
        
    }
   void solve(TreeNode *root, int k,int &h){
        
        if(!root) return;
        
        solve(root->left,k,h);
        h++;
        // cout<<h;
        if(h == k){
            // h = root->val;
            ans = root->val;
            return ;
        }
        
        solve(root->right,k,h);
        
        // return 0;
        
    }
};