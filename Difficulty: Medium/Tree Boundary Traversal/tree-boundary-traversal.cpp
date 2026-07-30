/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void TraversalKaLeft(Node *root,vector<int> &ans ){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            TraversalKaLeft(root->left,ans);
        }
        else{
            TraversalKaLeft(root->right,ans);
        }
    }
    // leaf node store kara rha hu
    void TraversalkaLeaf(Node *root, vector<int> &ans){
        if(root == NULL) return;
        if(root->left==NULL && root-> right==NULL){
            ans.push_back(root->data);
        }
        TraversalkaLeaf(root->left,ans);
        TraversalkaLeaf(root->right,ans);
    }
    // right ke liye 
    void Traversalkaright(Node *root, vector<int> &ans){
        if((root == NULL) || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            Traversalkaright(root->right,ans);
        }
        else{
            Traversalkaright(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        TraversalKaLeft(root->left, ans);
        TraversalkaLeaf(root->left,ans);
        TraversalkaLeaf(root->right,ans);
        Traversalkaright(root->right,ans);
        return ans;
    }
};