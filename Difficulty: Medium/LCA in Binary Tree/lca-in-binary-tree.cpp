/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root == NULL) return NULL;
        if(root->data == n1 || root->data == n2){
            return root;
        }
        Node* Llca = lca(root->left, n1, n2);
        Node* Rlca = lca(root->right, n1, n2);
        if(Llca!=NULL && Rlca!=NULL){
            return root;
        }
        else if(Llca!=NULL && Rlca==NULL) return Llca;
        else if(Llca==NULL && Rlca!=NULL) return Rlca;
        else return NULL;
        
    }
};