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
    int search(vector<int> &inorder,int ele){
    for(int i=0;i<inorder.size();i++){            
        if(inorder[i]==ele){                              
            return i;
        }
    }
    return -1;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int pree =0;
        return solve(preorder,pree,0,inorder.size()-1,inorder);
        
    }
    
     TreeNode* solve(vector<int>& preorder,int &prestart,
                     int instart,int inend, vector<int>& inorder){
         
        if(instart>inend){
        return NULL;
        }
        int ele = preorder[prestart++];
         TreeNode *root = new TreeNode(ele);
         
         int inroot = search(inorder,ele);
         root->left = solve(preorder,prestart,
                            instart,inroot - 1,inorder);
         root->right = solve(preorder,prestart,
                            inroot + 1,inend,inorder);
      return root;   
     }
};