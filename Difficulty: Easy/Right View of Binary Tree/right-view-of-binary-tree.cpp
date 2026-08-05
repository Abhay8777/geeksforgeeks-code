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
    vector<int> rightView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>rightView;
        queue<pair<Node*, int>>q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int lvl = temp.second;
            if(rightView.find(lvl) == rightView.end()){
                rightView[lvl] = frontNode->data;
            }
            if(frontNode->right) q.push(make_pair(frontNode->right, lvl+1));
            if(frontNode->left) q.push(make_pair(frontNode->left, lvl+1));
            
        }
        for(auto i:rightView){
            ans.push_back(i.second);
        }
        return ans;
    }
};