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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* tmp1 = new TreeNode(); 
            tmp1->val = val;
        if(root == NULL)
            return tmp1;
        TreeNode* tmp ,*curr = root;
        while(root){
            tmp = root;
            if(root->val > val)
                root = root->left;  
            else
                root = root->right;   
        }
        if(tmp->val > val)
            tmp->left = tmp1;
        else
            tmp->right = tmp1;
     return curr;   
    }
};