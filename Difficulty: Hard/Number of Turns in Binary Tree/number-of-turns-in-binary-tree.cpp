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
}; */

class Solution {
  public:

      bool findPath(Node* root, int target, vector<int>& path) {
          if (root == nullptr)
              return false;

          if (root->data == target)
              return true;

          // Go left
          path.push_back(0);
          if (findPath(root->left, target, path))
              return true;
          path.pop_back();

          // Go right
          path.push_back(1);
          if (findPath(root->right, target, path))
              return true;
          path.pop_back();

          return false;
      }

      int numberOfTurns(Node* root, int p, int q) {
          vector<int> pathP, pathQ;

          findPath(root, p, pathP);
          findPath(root, q, pathQ);

          // Find first different direction.
          int i = 0;

          while (i < pathP.size() &&
                 i < pathQ.size() &&
                 pathP[i] == pathQ[i]) {
              i++;
          }

          /*
              pathP[i...] = directions from LCA to p
              pathQ[i...] = directions from LCA to q
          */

          vector<int> path;

          for (int j = i; j < pathP.size(); j++)
              path.push_back(pathP[j]);

          // When moving from p towards LCA,
          // the direction is reversed.
          reverse(path.begin(), path.end());

          for (int j = i; j < pathQ.size(); j++)
              path.push_back(pathQ[j]);

          // Count changes in direction
          int turns = 0;

          for (int j = 1; j < path.size(); j++) {
              if (path[j] != path[j - 1])
                  turns++;
          }

          return turns == 0 ? -1 : turns;
      }
  };