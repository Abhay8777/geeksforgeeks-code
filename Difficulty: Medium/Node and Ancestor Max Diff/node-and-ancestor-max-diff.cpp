/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    int solve(Node* root, int maxAncestor) {
        if (root == nullptr)
            return INT_MIN;

        int ans = maxAncestor - root->data;

        maxAncestor = max(maxAncestor, root->data);

        int left = solve(root->left, maxAncestor);
        int right = solve(root->right, maxAncestor);

        return max({ans, left, right});
    }

    int maxDiff(Node* root) {
        return max(solve(root->left, root->data),
                   solve(root->right, root->data));
    }
};