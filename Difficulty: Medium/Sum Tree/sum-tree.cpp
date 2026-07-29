/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    int sum(Node* node){
        if(node == NULL) return 0;
        return node->data+ sum(node->left)+ sum(node-> right);
    }
  public:
    bool isSumTree(Node* node) {
        // code here
        if (node == NULL || (node->left == NULL && node->right == NULL))
        return true;
        int leftSum = sum(node->left);
        int rightSum = sum(node->right);
    
        return (node->data == leftSum +rightSum);
    }
};