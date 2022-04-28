// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>parent_map;
        Node * tr = solve(root,parent_map,target);
        
        queue<Node*> q;
        q.push(tr);
        map<Node*,bool> visited;
        visited[tr] = 1;
        // cout<<tr->data;
        int c =0;
        while(!q.empty()){
           
            c++;
            int s = q.size();
            while(s--){
             Node * tmp = q.front();
            q.pop();
            if(tmp->left && !visited[tmp->left]){
                visited[tmp->left] = 1;
                q.push(tmp->left);
                
                
            }
            if(tmp->right && !visited[tmp->right]){
                visited[tmp->right] = 1;
                q.push(tmp->right);
            }
            if(parent_map[tmp] && !visited[parent_map[tmp]]){
                visited[parent_map[tmp]] = 1;
                q.push(parent_map[tmp]);
            }
            }
            
           
        }
        c--;
        return c;
        
    }
    
    
    Node* solve(Node* curr, map<Node*,Node*> &mp,int t){
        
        queue<Node*> q;
        Node * rt;
        q.push(curr);
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            if(tmp->data == t)
                rt = tmp;
            if(tmp->left){
                mp[tmp->left] = tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                mp[tmp->right] = tmp;
                q.push(tmp->right);
            }
        }
        return rt;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends