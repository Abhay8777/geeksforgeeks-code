/* Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findpos(vector<int> &inorder, int elem, int n){
        for(int i = 0;i<n; i++){
            if(inorder[i] == elem) return i;
        }
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &index, int startIdx, int endIdx,int n){
        if( index < 0|| startIdx> endIdx){
            return NULL;
        }
        int element = postorder[index--];
        Node* root = new Node(element);
        int position = findpos(inorder, element, n);
        root->right = solve(inorder, postorder, index, position+1, endIdx, n);
        root->left = solve(inorder, postorder, index, startIdx, position-1, n);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n = inorder.size();
        int postOrderIdx = n-1;
        return solve(inorder, postorder, postOrderIdx, 0, n-1, n);
    }
};