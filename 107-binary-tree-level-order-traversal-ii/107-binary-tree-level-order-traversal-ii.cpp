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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL)
            return {};
        map<int,vector<int>> mp;
        
        queue<TreeNode*> q;
        q.push(root);
        int x = INT_MAX;
        while(!q.empty()){
            vector<int> l;
            // q.pop(); 
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* tmp = q.front();
                q.pop();
                l.push_back(tmp->val);
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right); 
            }
            mp[x] = l;
            x--; 
        }
        vector<vector<int>> vcc;
        for(auto x : mp){
            vector<int> vc;
            for(int xy  : x.second){
                vc.push_back(xy);
            }
        vcc.push_back(vc);   
        }
       return vcc; 
    }
};