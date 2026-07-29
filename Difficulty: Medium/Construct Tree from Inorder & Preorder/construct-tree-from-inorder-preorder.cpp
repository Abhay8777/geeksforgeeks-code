/*
Definition for Node
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
  public:
    int findpos(vector<int> &inorder, int elem, int n){
        for(int i = 0;i<n; i++){
            if(inorder[i] == elem) return i;
        }
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderstart, int inorderlast, int n){
        if(index>=n || inorderstart>inorderlast) return NULL;
        
        int elem = preorder[index++];
        Node* root = new Node(elem);
        int position = findpos(inorder, elem, n);
        
        root->left = solve(inorder, preorder, index, inorderstart, position-1, n);
        root->right = solve(inorder, preorder, index, position+1, inorderlast, n);
        return root;
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        
        int preOrderIndex = 0;
        int n = preorder.size();
        return solve(inorder, preorder, preOrderIndex, 0, n-1, n);
    }
};