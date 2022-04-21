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
    int findBottomLeftValue(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
        vector<int> vc;
        q.push(root);
        int z;
        bool t = true;
        while(!q.empty()){
            int size = q.size();
            int v;
            t = true;
            while(size--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
                if(t)
                    z = tmp->val;
                
                t = false;
                
            }
            // vc.push_back(v);
            
        }
        
        return z;
        
    }
};