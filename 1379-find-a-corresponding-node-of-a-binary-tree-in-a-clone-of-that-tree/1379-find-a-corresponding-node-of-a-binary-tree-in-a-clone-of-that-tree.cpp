/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* f = NULL;
        
        solve(original,cloned,target,f);
        
        return f;
        
    }

    void solve(TreeNode* o, TreeNode* c, TreeNode* t, TreeNode* &f){
        if(o == NULL || c == NULL)
            return;
        
        if(o == t){
            cout<<t->val;
            f = c;
            // return;
        }
        
        solve(o->left,c->left,t,f);
        solve(o->right,c->right,t,f);
    }
};