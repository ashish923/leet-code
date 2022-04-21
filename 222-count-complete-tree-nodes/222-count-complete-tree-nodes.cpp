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
        if(root == NULL) return {};
        queue<TreeNode*> q;
        // vector<vector<int>> ans;
        q.push(root);
        int c=0;
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
                // level.push_back(tmp->val);
                c++;
            
            }
            // ans.push_back(level);
        }
     return c;
        
    }
};