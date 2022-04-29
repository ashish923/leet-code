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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int lh = solve_left(root);
        int rh = solve_right(root);
        
        
        if(lh == rh) {
            return pow(2,rh) -1;}
        
        return countNodes(root->left) + countNodes(root->right) +1;
        
    }
    
    int solve_left(TreeNode* node){
        int l =0;
        while(node){
            l++;
            node = node->left;
            
        }
        return l;
    }
    int solve_right(TreeNode* node){
        int l =0;
        while(node){
            l++;
            node = node->right;
           
        }
        return l;
    }
};