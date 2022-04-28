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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mp;
       
        
        
        solve(root,mp);
        
        queue<TreeNode*> q;
        map<TreeNode* , bool> visited;
        q.push(target);
        int cnt =0;
        visited[target] = 1;
        while(!q.empty())
        {
            int s = q.size();
            if(cnt == k) break;
            cnt++;
            
            while(s--){
            TreeNode* a = q.front();
            q.pop();
                // cout<<a->val;
             if(a->left && !visited[a->left]){
                 visited[a->left] = 1;
                 q.push(a->left);
                 cout<<a->left->val;
             } 
             if(a->right && !visited[a->right]){
                 visited[a->right] = 1;
                 q.push(a->right);
             } 
                
             if( mp[a] && !visited[mp[a]]){
                 visited[mp[a]] = 1;
                 q.push(mp[a]);
                 
             }    
        }
            
        }    
            
     
        vector<int> vc;
            while(!q.empty()){
                TreeNode* ans = q.front();
                vc.push_back(ans->val);
                q.pop();
            }
            
       return  vc;
    }
               
    void solve(TreeNode* curr,map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
     
        q.push(curr);
        
       
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
        
            if(tmp->left){
                mp[tmp->left] = tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                mp[tmp->right] = tmp;
                q.push(tmp->right);
            }
        
        }
        
    }
};