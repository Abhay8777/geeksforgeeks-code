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
  public:
    int checkheight(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = checkheight(root->left);
        if(left == -1 ) return -1;
        int right = checkheight(root->right);
        if(right == -1) return -1;
        if(abs(left-right)>1) return -1;
        return 1+ max(left, right);
    }
    bool isBalanced(Node* root) {
        // code here
        if(root == NULL) return true;
        return checkheight(root) !=-1;
    }
};