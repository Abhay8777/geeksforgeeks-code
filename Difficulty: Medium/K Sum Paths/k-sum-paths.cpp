/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int solve(Node* root, int k, long long currSum, unordered_map<long long,int>& prefix) {
        if (!root) return 0;

        currSum += root->data;
        int count = 0;

        // check if there exists a prefix sum such that currSum - prefix = k
        if (prefix.find(currSum - k) != prefix.end()) {
            count += prefix[currSum - k];
        }

        // update prefix sum frequency
        prefix[currSum]++;

        // recurse left and right
        count += solve(root->left, k, currSum, prefix);
        count += solve(root->right, k, currSum, prefix);

        // backtrack
        prefix[currSum]--;

        return count;
    }

    int countAllPaths(Node* root, int k) {
        unordered_map<long long,int> prefix;
        prefix[0] = 1; // base case: empty path
        return solve(root, k, 0, prefix);
    }
};
