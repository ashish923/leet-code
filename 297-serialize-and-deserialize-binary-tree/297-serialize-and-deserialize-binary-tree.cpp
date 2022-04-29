/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        queue<TreeNode* > q;
        string s ="";
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
          
            if(tmp!=NULL){
                s += to_string(tmp->val)+',';
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else 
                s += "#,";
        }
        cout<<s;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        stringstream s(data);
        
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* tmp = q.front();
            q.pop();
            getline(s,str,',');
            if(str =="#"){
                
            }
            else {
                TreeNode* root1 = new TreeNode(stoi(str));
                tmp->left = root1;
                q.push(root1);
                
            }
            getline(s,str,',');
            if(str =="#"){
                
            }
            else {
                TreeNode* root1 = new TreeNode(stoi(str));
                tmp->right = root1;
                q.push(root1);
                
            }
            
            
        }
        
        
        return root;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));