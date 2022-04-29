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
    TreeNode* searchBST(TreeNode* root, int val) {
        // vector<int> vc;
       
        while(root){
            if(root->val == val){
               return root;
            }
            else if(root->val > val){
                // TreeNode * dum1 = new TreeNode();
                // dum1 = root;
                // dum->left = dum1;
                // vc.push_back(root->val);
                root = root->left;
                
            }
            else{
                // TreeNode* dum1 = new TreeNode();
                // dum1 = root;
                // dum->right = dum1;
                // vc.push_back(root->val);
                root = root->right;
            }
        }
        
        // if (b) return dum;
        return NULL;
        
    }
};