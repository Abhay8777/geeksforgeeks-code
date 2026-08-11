/* Definition for Node
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
    bool findPath(Node* root, int node, vector<int>& path) {
        if (!root) return false;
        
        path.push_back(root->data);
        
        if (root->data == node) return true;
        
        if (findPath(root->left, node, path) || findPath(root->right, node, path))
            return true;
        
        path.pop_back(); // backtrack
        return false;
    }
    
    int kthAncestor(Node *root, int k, int node) {
        vector<int> path;
        if (!findPath(root, node, path)) return -1;
        
        int idx = path.size() - k - 1;
        if (idx < 0) return -1;
        return path[idx];
    }
};
