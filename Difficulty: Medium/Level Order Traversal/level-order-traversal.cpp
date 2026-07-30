/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
         vector<int>result;
        if(root == NULL) return result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ans(n);
            for(int i =0; i<n;i++){
                Node* frontNode = q.front();
                q.pop();
                ans[i] = frontNode->data;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            for(auto i:ans){
                result.push_back(i);
            }
            
        }
        return result;
    }
};