/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    int height(Node* root) {
        // code here
        if(root == NULL){
             return -1;
        }
        int left = height(root -> left);
        int right = height(root -> right);
        
        
        
        return 1+ max(left, right);
    }
  public:
    int diameter(Node* root) {
        if(root == NULL) return 0;
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root->left)+height(root -> right)+2;
        int ans = max(op1, max(op2,op3));
        return ans;
        
    }
};